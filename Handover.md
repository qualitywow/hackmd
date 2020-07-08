# Handover
### Matlab Simulation
每秒衛星走7.5km，UE每秒來$\lambda_m$ or $\lambda_e$個

模擬UE出現地點，只考慮Central
- y axis: $beam_y \pm \frac{R}{2}$ 
- x axis: $beam_x \pm \frac{\sqrt{3}R}{2}$


### Prior Knowledge
#### 兩種資源管理方法
1. 在HO發生前保留資源，降低服務強制終止的機率
2. 把HO req放在queue裡，如果目前cell中的channel不夠用，HO queuing的等待時間會最久
=> 資源保留=>blocking rate低，要求較短的queuing delay=> terminated rate高
IRIDIUM衛星星座，coverage radius = 212.5km，66 SATs，繞極軌道高780km

#### 四種QoS參數
- $P_{bk}$: new call blocking prob. of class-k  
第k等級因為channel不夠而無法HO進去的new call比例
- $P_{fk}$: handover failure prob. of class-k call  
第k等級HO失敗的比例(含new call、handover call)
- $P_{dk}$: dropping prob. of class-k calls  
第k等級的new call沒有被block但還是HO失敗的比例(有資源卻沒成功)
- $P_{usk}$: unsuccessful call probability of class-k traffic  
第k等級的new call因為被block或drop而沒有成功HO的機率
- $\alpha_k$: dimensionless parameter，$\alpha_k=\frac{\sqrt3R}{V_{trk}T_{dk}}$ => 描述LEO移動性  
Tdk: the average duration time of class-k calls => call會持續多久

MS: Mobile Station  
作者預期overlap area中執行inter-beam HO，使call lifetime大幅增加  
source cell: 正在執行call，準備要轉接出去的那個MS cell

![Image](https://i.imgur.com/c6AIyUF.png)

#### LEO mobility assumptions
1. LEO會用Vtrk的速度通過MS所形成的cells
2. HO時，destination cell會是移動方向上的neighbor cell
3. MS形成的cell每隔一個offset會有一個，呈均勻分布
當有個call進到cell中，會產生一個隨機offset $z \in [-R, R]$
    - source cell: 呈現0~d(z)的均勻分布
    - destination cell: 恰好為d(z)


#### Conclusion
- 分析資源管理的性能
- 兩種handover priority scheme
  - HO queuing scheme
  - HO queuing scheme + guard channel
- 有guard channel的，在 handover failure 機率小幅提升下，大量降低 new call blocking, unsuccessful call 機率