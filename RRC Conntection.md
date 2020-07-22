# RRC Connection
RRC(Radio Resource Control)
透過signalling來配置user plane, control plane狀態；配置無線電資源
- conntion establish, release
- broadcast system information
- radio bearer establish, reconfigure, release
- RRC mobility procedure
- Paging notification, release
- Outer loop power control

## RRC sublayer功能
- 廣播有關 接入層(Access Stratum (AS))、非接入層(Non Access Stratum (NAS)) 系統訊息
- 由5GC or 5G接入網發起的paging
- UE與5G接入網的RRC連線建立、維護、釋放
  - 對載波聚合(Carrier Aggregation)的新增、修改、釋放
  - 對 NR中 or LTE-NR間 的雙重連接性(Dual Connectivity)的新增、修改、釋放
- 安全功能(含金鑰管理)
- 與信令無線電承載器(Signalling Radio Bearer (SRB))、資料無線電承載器(Data Radio Bearer (DRB))之間連線的建立、配置、維護、釋放
- 移動性功能
  - 換手(handover)、環境轉移(context transfer)
  - 對UE小區選擇(cell selection)、重選(reselection)的控制
- QoS管理功能
  - UE量測(measurement)報告、回報控制
  - 無線電鏈路(radio link)失效的偵測、復原
  - 幫UE和非接入層互通有無

## RRC State
![Image](https://i.imgur.com/KE1qsNK.png)

- NR-RRC CONNECTED
  - 5GC、5G-RAN都會在control plane, user plane和UE建立連線
  - UE在RAN的環境參數同時存在5G-RAN和UE上
  - 5G-RAN會知道UE屬於拿個RNA(RAN-Based Notification Area)
  - 可以和UE做雙向的unicast
  - 網路可以控制UE移動性 *IDLE/INACTIVE是透過cell reselect控制mobility
- NR-RRC INACTIVE
  - 廣播系統訊息
  - 因為移動性而重選cell
  - 被5G-RAN尋呼(paging)、管理
  - 非接入層 會為5G-RAN的paging配置不連續接收機制(Discontinuous Reception DRX)
  - 5GC、5G-RAN都會在control plane, user plane和UE建立連線
  - UE在RAN的環境參數同時存在5G-RAN和UE上
  - 5G-RAN會知道UE屬於拿個RNA(RAN-Based Notification Area)
- NR-RRC IDLE
  - 公用陸上行動網路(Public land mobile network (PLMN))選擇
  - 廣播系統訊息
  - 因為移動性而重選cell
  - 被5GC尋呼(paging)、管理
  - 非接入層 會為5GC的paging配置不連續接收機制(Discontinuous Reception DRX)

## Connection Control
> TS 38.331 Chap.5.3
### 5.3.1 Introduction
#### 5.3.1.1 RRC connection control
- RRC連線包含與SRB1建立連線。要先做完RRC連線才能和5G網路建立連線。(比從5GC收到UE context還早)
- 接入層安全在RRC連線的一開始還沒建好。剛開始建RRC連線的時候，NW會較UE提供測量報告，但UE只會在AS安全啟動之後才會送對應的資料。
- 在AS安全建立好之後，UE只會接受帶有同步訊息的重配置指示。
  
- 收到來自5GC的UE context後，RAN會啟動AS安全
- 用來啟動AS安全的RRC訊息受到完整性保護，加密是在AS安全啟動之後才開始
  ==== 目前為止，SRB1連線OK，RRC建立
- 之後和SRB2、DRB建連線的時候就已經有完整性保護、加密了
- 如果AS安全啟動失敗 or 無線電承載器連線失敗，RRC連線就要被釋放掉

- RRC連線的釋放(release)由NW發起，可將UE導到5G or 4G的載波頻率。
- RRC連線的暫停(suspend)由NW發起，UE會把inactive AS context或reconfig info存起來，轉換到RRC_IDLE
- 如果UE配有SCG(Secondary Cell Group)，UE發起RRC resume時會把SCG釋放掉

- UE要從RRC_INACTIVE換到RRC_CONNECTED，要由更高層啟動，或由RRC layer做RAN-Based Notification Area的更新，或由RAN做paging
- RRC連線resume後，NW會以UE存的AS context等訊息恢復AS安全、SRB、DRB

#### RRC_INACTIVE state
http://howltestuffworks.blogspot.com/2019/09/5g-nr-ue-rrc-states-and-state.html

- gNB可以送一個帶有suspendConfig的RRCRelease訊息，叫UE從RRC_CONNECTED換到RRC_INACTIVE。
- 把UE的配置改成RRC_INACTIVE所需要提供的欄位如下：
  -   fullI-RNTI (40-bits): Inactive-RNTI是在RRC_INACTIVE狀態中，用來辨識suspended UE context的暫時ID。一個在RRC_INACTIVE的UE可以透過Paging fullI-RNTI找到這個UE。
  -   shortI-RNTI (24-bits): 功能和fullI-RTNI相同，但用比較少個bit來表示。
  -   ran-NotificationAreaInfo: 用來做移動性管理，NW要確保UE在RRC_INACTIVE的期間仍然持續持有有效的ran-NotificationAreaInfo(RNA info)。
  -    ran-PagingCycle: UE的paging週期，給RAN paging用。
  -   t380: 觸發UE週期性RNA更新程序的計時器。

當UE需要從RRC_INACTIVE狀態轉換到RRC_CONNECTED狀態時，
  1. 可以由higer layer啟動RRCResume or
  2. 由RRC層執行RNA更新 or
  3. 從NG-RAN進行RAN尋呼
RRC連接恢復過程會重新啟動AS安全性並重新建立SRB和DRB。

##### SuspendConfig
SuspendConfig ::=                   SEQUENCE { 
    fullI-RNTI                          I-RNTI-Value, 
    shortI-RNTI                         ShortI-RNTI-Value, 
    ran-PagingCycle                     PagingCycle, 
    ran-NotificationAreaInfo            RAN-NotificationAreaInfo                                                OPTIONAL,   -- Need M 
    t380                                PeriodicRNAU-TimerValue                                                 OPTIONAL,   -- Need R 
    nextHopChainingCount                NextHopChainingCount, 
    ... 
}


- 收到恢復RRC連接的請求，NW可以
  - resume暫停的RRC連接並將UE換成RRC_CONNECTED or
  - 拒絕該resume並將UE換成RRC_INACTIVE的請求(要他等一段時間) or
  - 直接re-suspend RRC連接並將UE換成RRC_INACTIVE or
  - 直接釋放RRC連接並將UE換成RRC_IDLE or
  - 指示UE啟動NAS級別恢復。
  - 
![Image](https://i.imgur.com/DNzAh6P.png)
- Scenario1: Successful RRC connection resumption. Transition from RRC_INACTIVE to RRC_CONNECTED.
- Scenario2: RRC connection resume fallback to RRC connection establishment. Transition from RRC_INACTIVE to RRC_CONNECTED.
- Scenario3: RRC connection resume followed by network releasing RRC connection. Transition from RRC_INACTIVE to RRC_IDLE.
- Scenario4: RRC connection resume followed by network suspend. Transition from RRC_INACTIVE to RRC_INACTIVE.
- Scenario5: RRC connection resume followed by network reject. Transition from RRC_INACTIVE to RRC_INACTIVE.

- RRC resume和建立RRC連線時一樣，要經過CBRA，在Msg3發送RRCResumeRequest/RRCResumeRequest1(UL CCCH)。此訊息是從SRB0用Transparent Mode送出去。
- Resume request msg如下：
  ![Image](https://i.imgur.com/X9beBPW.png)
  - 要選哪個？
    - The network informs the UE in SIB1 which I-RNTI to be used while resuming the connection (in the RRCResumeRequest message). If the field useFullResumeID is present in SIB1, the UE shall use fullI-RNTI, otherwise, the UE shall use shortI-RNTI.
    - While resuming the connection, if fullI-RNTI to be used, the UE sends RRCResumeRequest1 message and includes fullI-RNTI as resumeIdentity, else if shortI-RNTI to be used, the UE sends RRCResumeRequest message and includes shortI-RNTI as resumeIdentity.

- 收到resume request後，NW會發一個RRCResume(DCCH)來resume被暫停的RRC連線。RRCResume會在SRB1用Acknowledge Mode送。UE確認完成會在SRB1用Acknowledge Mode送一個RRCResumeComplete回去。
### 5.3.2 Paging
UE在RRC_IDLE or RRC_INACTIVE狀態，NW傳送paging info.給UE
NW可能把要給多個UE的paging msg放在一個PagingRecord中，傳給每個UE


### DRX(Discontinous Reception)
https://www.sharetechnote.com/html/Handbook_LTE_DRX.html

不連續接收機制，讓UE可以不要一直聽，沒事就去睡。

- UE本來會一直監聽PDCCH，看有沒有東西要DL給自己。但其實UE可能不會一直有東西可以收，容易發生overhearing，浪費電量。
雖然在睡的時候會讓UE收資料比較不那麼即時，但只要不太影響使用者體驗其實沒關係。

- 一個DRX cycle會分成兩段，**ON_duration**是UE聽PDCCH的時間，剩下的時間就可以去睡。
- 為了避免UE去睡使得整個傳輸拖得更久，DRX中有個DRX inactive timer機制，讓UE要聽完ON_duration後，要再聽完DRX inactive timer數完，才可以真的去睡。
  
- DRX inactive timer 太久 => 沒DL了，UE還得一直聽，沒法馬上去睡
- MAC layer中的DRX command可以讓UE更快進入睡眠狀態(Go-To-Sleep CE)
- 當NW偵測到已經沒有要DL東西給UE(or UE沒有要做UL)，可以讓UE送一個MAC PDU，UE收到就知道可以去睡
> PDU(Protocol Data Unit)



