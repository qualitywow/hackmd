# TR 38 series





### 28.213
trigger RA: 
1. request of a PRACH by higer layer (UE 主動)
2. request of a PRACH by PDCCH(BS 發起)

由UE發起的RA，要在higher layer準備好一些配置，如：frame numerology, preamble index, ... etc.

一個PRACH是由選定的PRACH format以傳輸功率$P_{PRACH,b,f,c}$傳送

> A UE determines a transmission power for a physical random access channel (PRACH),$P_{PRACH,b,f,c}(i)$, on active UL BWP $b$ of carrier $f$ of serving cell $c$ based on DL RS for serving cell.
