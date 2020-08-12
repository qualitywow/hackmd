# Handover-MarkovChain
## 參數定義

### 場景參數
- C: channel總數
- Ch: guard channel的個數
- Tinact: inactivity timer 時間(單位:秒)
- L: 矩形cell的長度(單位:公里)
- Lo: 矩形overlap area的長度(單位:公里)
- Vtrk: 衛星相對於地面的移動速度(單位:公里/秒)

衛星經過所需的時間
- TL: 衛星經過矩形區域所需的時間($TL = \frac{L}{Vtrk}$)
- TO: 衛星經過矩形overlap area所需的時間($TL = \frac{Lo}{Vtrk}$)

### User參數
bm: mMTC call占用的channel數量
be: eMBB call占用的channel數量
M: 最大mMTC call個數($M = \frac{C}{bm}$)
E: 最大eMBB call個數($M = \frac{C}{be}$)
Tcall_m: mMTC call 的平均連線持續時間(單位:秒)
Tcall_e: eMBB call 的平均連線持續時間(單位:秒)

### 基礎公式
- 在cell中的UE進行handover的機率 `Pn(c,x)`  
  (The handover probability for a call in the source cell)  
  $P^m_{n,x}$: mMTC new call 以 class-x 出去
  $P^e_{n,x}$: eMBB new call 以 class-x 出去

## 論文解釋
### III、IV
- UE平均進行上/下行傳輸時間之PDF(只寫mMTC，m換e，即eMBB)
  - $pdf_{t_{call, m}}(t) = \frac{1}{T_{call,m}} e^{\frac{-t}{T_{call,m}}},$ if $t \geq 0$
  - $pdf_{t_{call, m}}(t) = 0,$ if $t < 0$
- Handover種類(依進行handover分)
  - class-A: 一進入overlap area就進行handover
  - class-B: 到overlap area中線再進行handover
  - class-C: 到overlap area邊緣才進行handover
- Crowded or not?
  - $\Lambda(N)$: available channel，$C_h$: guard channel
  - case1: $\Lambda(N) > C_h$ // not crowded
  - case2: $0 \leq C_h \leq \Lambda(N)$ // crowded
### V
1. $t_x$: new call進、class-x出，中間經過的時間，假設經過t時間的機會均等。
  - 不論new call以何種出去，最多都是經過一個cell的時間(即$T_L$)
  - pdf for x = a, b, c
    - $pdf_{t_a} = \frac{1}{T_L}, 0 \leq t \leq T_L; \ pdf_{t_a} = 0,$ otherwise
    - $pdf_{t_b} = \frac{1}{T_L}, \frac{L_o}{2} \leq t \leq T_L+\frac{L_o}{2}; \ pdf_{t_b} = 0,$ otherwise
    - $pdf_{t_c} = \frac{1}{T_L}, T_o \leq t \leq T_L+T_o; \ pdf_{t_c} = 0,$ otherwise
2. $T^y_x$: class-y進、class-x出，中間經過的時間
  - $T^y_x = \frac{D_x - O_y}{V_{trk}}$，$D_x$以class-b進為基準，再用$O_y$調成class-A或class-B。
    - $D_x$
      - $= L-\frac{L_o}{2}, if \ x = a$
      - $= L, if \ x = b$
      - $= L+\frac{L_o}{2}, if \ x = c$
    - $O_y$
      - $= -\frac{L_o}{2}, if \ y = a$
      - $= 0, if \ y = b$
      - $= \frac{L_o}{2}, if \ y = c$
3. 