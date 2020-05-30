# CoDoC: A Novel Attack for Wireless Rechargeable Sensor Networks through Denial of Charge
###### tags: `Paper`

## Introduction
近幾年有可以充電的sensor network，之前的研究都是再進行排程和系統優化等，對充電的安全性疑慮和威脅不太管。這篇paper設計了一個充電攻擊的方法。

本篇論文要討論Denial of Charge的問題
- 作者為了設計充電攻擊，制定了一個充電請求模型
- 也設計了一個用來預測充電請求的方法
- 最後設計了一個協作式的充電攻擊演算法

### 三項挑戰
:::spoiler
1. how to propose a generalized ondemand charging architecture model, which is feasible for presenting various kinds of on-demand charging approaches by configuring different parameters?
2. when and how to determine the best time to manipulate malicious nodes to simultaneously send fake requests so as to maximize destructiveness?
3. how to disguise the presence of the attack without notice/detection of the WCV?
:::
1. 如何提出一種通用的按需充電架構模型，通過配置不同的參數來提出各種按需充電方法是可行的？
2. 如何確定哪時候是操縱惡意節點同時發送假請求以最大程度地破壞性的最佳時間？
3. 如何在WCV不通知/未發現的情況下掩蓋攻擊的存在？

### 主要貢獻
:::spoiler
- To the best of our knowledge, we are the first to concentrate on charging attacks in WRSNs. A Collaborative Denial of Charge (CoDoC) attack, which destructs a network by maximizing event loss through intentionally tempering, modifying and generating fake charging requests, is proposed.
- To maximize attacking destructiveness (e.g. maximizing missing point of interests (PoIs) & missing events), we abstract the features of state-of-the-art on-demand charging architecture and develop a generalized model for formalizing the charging scheduling procedure, which provides the fundamental basis for designing charging attacks.
- To find the best opportunity for launching the DoC attack, a request prediction method (RPM) is proposed. RPM can be used to predict the number of upcoming requests initiating in a certain interval, within which charging demand exceeds a WCV’s charging capability, yielding some nodes’ requests ignored, and exhausted in vain.
:::
- 據我們所知，我們是第一個專注於WRSN中的充電攻擊的人。提出了一種"協同拒絕充電"(CoDoC)攻擊，該攻擊通過故意調整，修改和生成虛假充電請求來最大程度地減少事件損失，從而破壞了網路。
- 為了最大程度地提高攻擊性的破壞性(例如，最大程度地減少興趣點(PoI)和丟失事件)，我們對最新的按需充電架構的功能進行了抽象，並開發了一個通用模型來規範充電排程程序， 為設計充電攻擊提供了基礎。
- 為了找到發動DoC攻擊的最佳機會，提出了一種請求預測方法(RPM)。RPM可用於預測在一定間隔內啟動的即將到來的請求的數量，在此間隔內，充電需求超過WCV的充電能力，導致某些節點的請求被忽略，並且徒勞無用。

## On-Demand Architecture Generalization
### A. Network Model
WRSN = BS + WCV + Nodes
BS: 從Nodes蒐集資料, 供電, 置換WCV的服務
WCV: 無線充電，電池容量有上限，沒電要回去BS充電
Node: 兩線圈距離內可充電
### B. Charging Scheduling Scheme
考慮彈性、可擴充的動態拓樸。如果是週期性的充電排程，充電順序一開始就決定好了，那惡意攻擊就不會使充電排程演算法做出改變，就不能造成危害了。
作者的充電排程中考慮(1)distance(2)charging deadline，是個適應性高的排程方法


$n_i$ at $(x_i, y_i)$
$q_i$: current energy comsumption rate
$T_i$: current time
$n_i = <i, x_i, y_i, q_i, T_i>$

$\theta$: charging threshold
$\Psi$: charging waiting queue

用node priority選誰先服務，每當有node充電完成就更新$\Psi$

#### 1) Priority determination
![Image](https://i.imgur.com/YrWcjVw.png)
- $\lambda^{(m)} (i)$，值越小，priority越高

![Image](https://i.imgur.com/6eTNOQP.png)

#### 2) Reachable-in-Time Test

#### 3) Charging time calculation

### C. General Model for On-Demand Charging Scheduling
### D. Adversary Model

- 為了避免被BS發現攻擊，送fake request要有些限制
- $\Theta^{(m)}_i$: malicious node $m_i$的energy warning threshold
- malicous node要符合下面幾個限制才會做出攻擊
    - Rest-Lifetime-Constraint
    - Upper-Bound-Constraint
    - Lower-Bound-Constraint

![Image](https://i.imgur.com/YH0jJ03.png)

## The Proposed Scheme
請求長相 $n_i = <i, x_i, y_i, q_i, T_i>$
### A. Request Prediction Method
告訴我們$q_i$怎麼算出來的，$n_i$送充電請求的時間$T_i$的預測式 $T_i = T'^{(f)}_i + \frac{C^{(n)}-\Theta}{q_i}$

### B. CoDoC Attack Algorithm
攻擊者可以操控惡意節點發出假請求，$n_i = <i, x_i, y_i, \boldsymbol{q_i}, \boldsymbol{T_i}>$

最大化攻擊傷害 => 讓最多的節點死掉
- 在$Re^{(m)}$中，要加入多少fake request?
- 在哪個時間$T^{(m)}$送fake request是最好的?
- 惡意節點的能量消耗率$q^{(m)}$應該要給多少?

定義節點死掉
