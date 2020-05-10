# DVB-S2
DVB-S2 (Digital Video Broadcasting - Satellite 2nd generation)

#### 與先前版本比較
|項目|DVB-S|DVB-S2|DVB DSNG|
|-|- |-|-|
|Error Correction (FEC)|Reed-Solomom & Convolution|BCH、LDPC|Reed-Solomom & Convolution|
|Modulation|QPSK|8PSK、16APSK、32APSK|QPSK、8PSK、16QAM|
|資料格式|MPEG2 TS bit stream|多種資料格式，可並行輸入[(圖一)](#圖一)，以frame為基礎||
- DVB-S2所提供資料傳輸量非常接近於Shannon-Limit所定義的理想資料傳送容量
- DVB-S2解調(demodulation)的工作處理簡單，只要處理相位(phase)變化
- DVB-S2有較高的抗雜訊能力
- BCH、LDPC可組成不同的code rate，提供不同的資料傳輸能量與錯誤糾正的能力[(圖二)](#圖二)

#### frame 架構
- 在PHY layer傳送時，整個FEC frame會切成$n$個time slot來傳，可能是16或32個time slot為傳送的標準。32個time slot的會包含PL header。[(圖三)](#圖三)
- PL header time slot 資訊
    - 同步的時序資訊
    - 同步的Pilot資訊
    - Frame架構資訊
    - PHY layer資料傳送調變、Code Rate
    - 一般用$\frac{\pi}{2}$-shift BPSK調變，如16APSK、32APSK

對於 DVB-S2標準的應用來說，最主還是應用在 HDTV高畫質的電視節目資料傳送上，一般 HDTV高畫質的電視節目內容是透過H.264或是MPEG-4 AVC的壓縮編碼後來再經由DVB-S2標準下的衛星訊號來傳送。

不太清楚 symbol rate / data rate 換算的公式，但舉例說明的部分和用[計算機](https://www.satcomresources.com/symbol-rate-to-data-rate-calculator)算出來的一樣。

##### 16APSK
$log_2(16) = 4$ bit => 一個symbol對應4個bits。[(圖四)](#圖四)
星狀圖上有16個symbols，DVB-S2標準的定義下，共有2組半徑為訊號的大小與8個相位組成。
不同code rate會有不同的半徑、星狀圖上的位置會不同。[(圖五)](#圖五)

##### 32APSK
$log_2(32) = 5$ bit => 一個symbol對應5個bits。[(圖六)](#圖六)
星狀圖上有32個symbols，DVB-S2標準的定義下，共有3組半徑為訊號的大小與6個相位組成。
不同code rate會有不同的半徑、星狀圖上的位置會不同。[(圖七)](#圖七)

#### 判斷衛星訊號品質的相關參數
- 訊號強度
- 誤碼率 (Bit Error Rate)
- 訊雜比 (Carrier Noise Ratio)
- Eb/No
- MER (Modulation Error Rate)
- Shoulder Attenuation




#### Figure table
###### (圖一)
![Image](https://i.imgur.com/xiFYEwQ.png)

---
###### (圖二)
![Image](https://i.imgur.com/JA5nznN.png)

---
###### (圖三)
![Image](https://i.imgur.com/RnBmAIx.png)

---
###### (圖四)
![Image](https://i.imgur.com/9tEGClT.png)

---
###### (圖五)
![Image](https://i.imgur.com/oWYNHPI.png)

---
###### (圖六)
![Image](https://i.imgur.com/DNhEUq6.png)

---
###### (圖七)
![Image](https://i.imgur.com/ZzYxIld.png)





節錄自：
- [第二代數位衛星廣播DVB-S2標準訊號的應用量測](http://www.ctimes.com.tw/news/201108/12/rs12.pdf)
- [DVB-2 Baseband Verification Library Parts](https://edadocs.software.keysight.com/display/sv201007/DVBS2+Baseband+Verification+Library+Print+View)