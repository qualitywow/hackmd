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

### Input n: new, q: ho
lambda_n_m: mMTC new call arrival rate
lambda_n_e: eMBB new call arrival rate

- 新進的UE要HO到下一個cell
  - Nn_mx: new call mMTC class-x handover call arrival rate
  - Nn_ex: new call eMBB class-x handover call arrival rate
- 本來就是HO call，要再HO到下一個cell
  - Nq_mx: ho call mMTC class-x handover call arrival rate
  - Nq_ex: ho call eMBB class-x handover call arrival rate
- 以class-x來看的總體ho call arrival rate
  - lambda_qx_mx
  - lambda_qx_ex
- 三者總和為以device type來看的總體ho call arrival rate
  - lambda_qx_m
  - lambda_qx_e



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
3.  $P_{n,x}^m$: mMTC new call用class-x出去機率
    $P_{n,x}^e$: eMBB new call用class-x出去機率
4.  $P_{active,y}^m$, $P_{active,y}^e$: UE要用class-y出去但inact timer還沒數完 // 可以省掉的handover? 
    $P_{q,y,x}^m$, $P_{q,y,x}^e$: UE用class-y進來，用class-x出去機率
5.  intra-cell channel holding time
  - new call UE用class-x出去的intra-cell channel holding time
    - mMTC: $t_{n,x}^m=min(t_{call,m}+T_{inact},\ t_x)$
    - eMBB: $t_{n,x}^e=min(t_{call,e}+T_{inact},\ t_x)$
  - 用class-y進來、class-x出去的intra-cell channel holding time
    - mMTC: $t_{q,y,x}^m=min(t_{call,m}+T_{inact},\ T_x^y)$ 
    - eMBB: $t_{q,y,x}^e=min(t_{call,e}+T_{inact},\ T_x^y)$
  - 上面兩個mean value(用算期望值的方式算)
    - mMTC: 
      - $E(t_{n,x}^m) = {(T}_{call,m}+T_{inact})\ast\left(1-P_{n,x}^m\right)$
      - $E(t_{q,y,x}^m) ={(T}_{call,m}+T_{inact})\ast\left(1-P_{q,y,x}^m\right)$
    - eMBB: 
      - $E(t_{n,x}^e) = {(T}_{call,e}+T_{inact})\ast\left(1-P_{n,x}^e\right)$
      - $E(t_{q,y,x}^e) ={(T}_{call,e}+T_{inact})\ast\left(1-P_{q,y,x}^e\right)$
6. Handover call arrival rate: 
   - mMTC: $\lambda_{q,y,x}^m= \frac{N_n^mP_{n,x}^m}{T_L+T_x} + \frac{N_n^qP_{q,y,x}^m}{T_x^y}$
   - eMBB: $\lambda_{q,y,x}^e= \frac{N_n^eP_{n,x}^e}{T_L+T_x} + \frac{N_n^qP_{q,y,x}^e}{T_x^y}$
   - 前一個cell的new call數量； 前一個cell的ho call數量
     - mMTC: $N_n^m$；$N_q^m$
     - eMBB: $N_n^e$；$N_q^e$
7. New call arrival rate:
  - mMTC: $\lambda_n^m$
  - eMBB: $\lambda_n^e$
8. $P_{rn,y}^m$: mMTC new call占用channel的機率
   $P_{rq,y}^m$: mMTC 用class-y進，class-x出的ho call占用channel的機率
   $P_b^m$: mMTC new call blocking probability
   $P_f^m$: mMTC ho call failure probability
   (換成e即為eMBB)
9. 當UE以class-y進來、class-x出去，intra-cell holding time
   $\mu_{m,y,x}^-1 = P_{rn,y}^mE(t_{n,x}^m)+P_{rq,y}^mE(t_{q,y,x}^m)$
   $\mu_{e,y,x}^-1 = P_{rn,y}^eE(t_{n,x}^e)+P_{rq,y}^eE(t_{q,y,x}^e)$