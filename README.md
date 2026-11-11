# TH3 – Tầng mạng, kết nối không dây

## 1. Thông tin sinh viên

- Họ và tên: Vi Tuấn Kiệt
- Mã sinh viên: 25112063
- Lớp: BCSE2025
- Vi điều khiển: ESP32 DevKit V1
- Công cụ mô phỏng: Wokwi
- Ngôn ngữ lập trình: Arduino C++

## 2. Giới thiệu

Bài thực hành TH3 gồm 5 nội dung nhằm tìm hiểu và thực hành các chức năng giao tiếp của vi điều khiển ESP32.

Do không có bộ kit phần cứng thực tế, toàn bộ chương trình được xây dựng và kiểm tra bằng phần mềm mô phỏng Wokwi.

Các nội dung thực hiện:
1. Wi-Fi AP/STA.
2. BLE Server.
3. ESP-NOW Transmitter/Receiver.
4. HTTP Web Server điều khiển LED.
5. MQTT Publish/Subscribe.

---

## 3. Nội dung thực hiện

### Bài 1 – Wi-Fi AP/STA

**Mục tiêu:**

Tìm hiểu hai chế độ hoạt động Wi-Fi của ESP32:

- AP (Access Point): ESP32 tạo ra một mạng Wi-Fi riêng để thiết bị khác kết nối.
- STA (Station): ESP32 kết nối với một mạng Wi-Fi có sẵn.

**Cách thực hiện:**

- Sử dụng thư viện `WiFi.h`.
- Cấu hình ESP32 hoạt động đồng thời ở chế độ AP và STA.
- Tạo mạng Wi-Fi có tên `ESP32_AP`.
- Kết nối với mạng Wi-Fi mô phỏng `Wokwi-GUEST`.
- Hiển thị địa chỉ IP trên Serial Monitor.

**Kết quả:**

ESP32 khởi tạo được mạng Wi-Fi AP và kết nối được với mạng Wi-Fi STA trong môi trường Wokwi.

**Minh chứng:** Ảnh Serial Monitor 
https://drive.google.com/file/d/1A_zwURwwfdbxT47mbzCeDHRIJIWJkIdD/view?usp=sharing

---

### Bài 2 – BLE Server

**Mục tiêu:**

Tìm hiểu giao tiếp Bluetooth Low Energy (BLE) trên ESP32.

**Cách thực hiện:**

- Khởi tạo BLE Server.
- Tạo Service và Characteristic.
- Sử dụng UUID để định danh Service và Characteristic.
- Chuẩn bị chương trình để thiết bị BLE Client có thể kết nối và trao đổi dữ liệu.

**Kết quả:**

Đã xây dựng mã nguồn BLE Server. Tuy nhiên, môi trường Wokwi không hỗ trợ đầy đủ việc mô phỏng và kiểm tra kết nối BLE Client trong bài thực hành này. Vì vậy, chưa xác nhận được quá trình kết nối và trao đổi dữ liệu BLE thực tế.

**Minh chứng: ảnh Serial Monitor 
https://drive.google.com/file/d/1kkBBMFrvX1A6mOyDAEGLBm89UluwrTxc/view?usp=sharing

---

### Bài 3 – ESP-NOW Transmitter/Receiver

**Mục tiêu:**

Tìm hiểu phương thức truyền dữ liệu ESP-NOW giữa các thiết bị ESP32 mà không cần thông qua Router Wi-Fi.

**Cách thực hiện:**

Bài thực hành gồm hai chương trình:

**Transmitter (bộ gửi):**
- Khởi tạo Wi-Fi ở chế độ phù hợp.
- Khởi tạo giao thức ESP-NOW.
- Tạo dữ liệu cần gửi gồm ID và giá trị.
- Gửi dữ liệu đến địa chỉ MAC của thiết bị nhận.

**Receiver (bộ nhận):**
- Khởi tạo ESP-NOW.
- Đăng ký hàm nhận dữ liệu.
- Hiển thị ID và giá trị nhận được trên Serial Monitor.

**Kết quả:**

Đã xây dựng mã nguồn cho cả Transmitter và Receiver. Đã kiểm tra quá trình khởi tạo riêng từng chương trình. Tuy nhiên, hai project Wokwi riêng biệt không trao đổi ESP-NOW trực tiếp được trong môi trường mô phỏng đã sử dụng, nên chưa xác nhận được truyền nhận dữ liệu đầu cuối.

**Minh chứng:** ảnh khởi động riêng của:
reciver https://drive.google.com/file/d/1fUHHQNDQtVTW_kahVQ8p1VKh65fpZPQo/view?usp=sharing

Transmitter  https://drive.google.com/file/d/1MIncOLXEsTXKat-SSCrAkWk9-93nGw7h/view?usp=sharing

---

### Bài 4 – HTTP Web Server điều khiển LED

**Mục tiêu:**

Xây dựng Web Server trên ESP32 để điều khiển bật và tắt LED thông qua trình duyệt.

**Cách thực hiện:**

- Sử dụng thư viện `WiFi.h` và `WebServer.h`.
- Kết nối ESP32 với mạng Wi-Fi `Wokwi-GUEST`.
- Khởi tạo HTTP Web Server tại cổng 80.
- Tạo trang web có hai nút:
  - BẬT LED.
  - TẮT LED.
- Sử dụng chân GPIO 2 để điều khiển LED.
- Sử dụng điện trở 220 ohm mắc nối tiếp với LED.

**Các đường dẫn xử lý:**

- `/`: Hiển thị trang điều khiển LED.
- `/on`: Bật LED.
- `/off`: Tắt LED.

**Kết quả:**

ESP32 kết nối Wi-Fi thành công, hiển thị địa chỉ IP và khởi động HTTP Web Server thành công trên Wokwi.

Tuy nhiên, do giới hạn kết nối từ trình duyệt bên ngoài vào ESP32 trong môi trường mô phỏng đang sử dụng, chức năng điều khiển LED thông qua trình duyệt chưa được kiểm chứng đầu cuối.

**Minh chứng:** 
sơ đồ mạch  https://drive.google.com/file/d/1q7BouvANNM43zf0yYfc4xj8vV9g2LR37/view?usp=sharing

ảnh monitor https://drive.google.com/file/d/1dTdJUc4AiT3NgEx8sxoIC-iJtp3ht6vZ/view?usp=sharing
---

### Bài 5 – MQTT Publish/Subscribe

**Mục tiêu:**

Tìm hiểu giao thức MQTT và thực hành gửi, nhận dữ liệu giữa ESP32 và MQTT Broker.

**Cách thực hiện:**

- Sử dụng thư viện `WiFi.h`.
- Sử dụng thư viện `PubSubClient.h`.
- Kết nối ESP32 với mạng Wi-Fi `Wokwi-GUEST`.
- Kết nối MQTT Broker `broker.hivemq.com` qua cổng 1883.
- Đăng ký Subscribe để nhận dữ liệu.
- Publish dữ liệu cảm biến giả lập gồm nhiệt độ và độ ẩm sau mỗi 5 giây.

**Topic sử dụng:**

- Topic Publish: `TH3/[SV_ID]/sensor`
- Topic Subscribe: `TH3/[SV_ID]/control`

Trong đó `[SV_ID]` được thay bằng mã sinh viên của người thực hiện.

**Dữ liệu Publish mẫu:**

```json
{
  "sv_id": "SV001",
  "temperature": 28,
  "humidity": 65
}
```

**Kết quả:**

- ESP32 kết nối Wi-Fi thành công.
- Kết nối MQTT Broker thành công.
- Đăng ký Subscribe thành công.
- Publish dữ liệu lên topic sensor.
- Gửi tin nhắn kiểm tra `TEST_SUBSCRIBE` lên topic control.
- ESP32 nhận lại tin nhắn `TEST_SUBSCRIBE` từ MQTT Broker.

Việc kiểm tra Subscribe được thực hiện bằng cách gửi và nhận lại tin nhắn thông qua Broker. Chưa kiểm tra bằng một MQTT Client độc lập do gặp lỗi kết nối WebSocket trên trình duyệt.

**Minh chứng:** Ảnh Serial Monitor thể hiện kết nối MQTT, Publish và nhận `TEST_SUBSCRIBE`.
ảnh monitor https://drive.google.com/file/d/1f-IF2TaoDUdq10LPJ1x3DP5eJFQxha9j/view?usp=sharing

---

## 4. Cấu trúc thư mục

```text
TH3/
│
├── Bai1_WiFi_AP_STA/
│   ├── sketch.ino
│   └── Bai1_WiFi.png
│
├── Bai2_BLE_Server/
│   ├── sketch.ino
│   └── README.md
│
├── Bai3_ESP_NOW/
│   ├── Transmitter/
│   │   └── sketch.ino
│   ├── Receiver/
│   │   └── sketch.ino
│   └── README.md
│
├── Bai4_HTTP_WebServer_LED/
│   ├── sketch.ino
│   ├── diagram.json
│   └── Bai4_HTTP_Server.png
│
├── Bai5_MQTT/
│   ├── sketch.ino
│   ├── libraries.txt
│   └── Bai5_MQTT.png
│
└── README.md
```

## 5. Công cụ sử dụng

- Wokwi: Mô phỏng ESP32 và kiểm tra chương trình.
- Arduino C++: Ngôn ngữ lập trình.
- GitHub: Lưu trữ và nộp mã nguồn.
- HiveMQ Public Broker: Máy chủ MQTT dùng để thử nghiệm.

## 6. Kết luận

Qua bài thực hành TH3, em đã tìm hiểu và xây dựng chương trình cho năm nội dung giao tiếp trên ESP32 gồm Wi-Fi, BLE, ESP-NOW, HTTP Web Server và MQTT.

Thông qua quá trình thực hiện, em hiểu thêm cách cấu hình Wi-Fi, xây dựng máy chủ, gửi và nhận dữ liệu giữa các thiết bị cũng như sử dụng giao thức MQTT trong hệ thống IoT.

Do sử dụng môi trường mô phỏng Wokwi và không có bộ kit phần cứng thực tế, một số chức năng như BLE, ESP-NOW và điều khiển HTTP qua trình duyệt chưa được kiểm chứng hoàn chỉnh.

Em sẽ tiếp tục kiểm tra và hoàn thiện các chức năng này khi có điều kiện sử dụng phần cứng thực tế.
