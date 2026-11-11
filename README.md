# TH3 – Tầng mạng, kết nối không dây

Họ và tên: Vi Tuấn Kiệt
Mã sinh viên: 25112063
Lớp: BCSE2025
Vi điều khiển: ESP32 DevKit V1
Môi trường lập trình: VS Code + PlatformIO (C++, framework Arduino)
Công cụ mô phỏng: Wokwi  (không có bộ kit thực tế)

## Nội dung thực hiện

Bài 1 – Wi-Fi AP/STA:
ESP32 tạo mạng AP tên ESP32_AP, đồng thời kết nối STA vào mạng Wokwi-GUEST và hiển thị địa chỉ IP trên Serial Monitor. Chạy thành công trong Wokwi.
Monitor: https://drive.google.com/file/d/1A_zwURwwfdbxT47mbzCeDHRIJIWJkIdD/view?usp=sharing

Bài 2 – BLE Server:
Đã xây dựng mã nguồn BLE Server với Service và Characteristic. Wokwi không hỗ trợ đầy đủ BLE Client nên chưa xác nhận được kết nối và trao đổi dữ liệu.
Monitor: https://drive.google.com/file/d/1kkBBMFrvX1A6mOyDAEGLBm89UluwrTxc/view?usp=sharing

Bài 3 – ESP-NOW Transmitter/Receiver:
Đã xây dựng mã nguồn cho bộ gửi và bộ nhận, từng chương trình khởi tạo được riêng. Hai project Wokwi riêng biệt không trao đổi ESP-NOW trực tiếp được nên chưa xác nhận truyền nhận đầu cuối.
Monitor Receiver: https://drive.google.com/file/d/1fUHHQNDQtVTW_kahVQ8p1VKh65fpZPQo/view?usp=sharing
Monitor Transmitter: https://drive.google.com/file/d/1MIncOLXEsTXKat-SSCrAkWk9-93nGw7h/view?usp=sharing

Bài 4 – HTTP Web Server điều khiển LED:
ESP32 kết nối Wokwi-GUEST, khởi động Web Server cổng 80 với các đường dẫn /, /on, /off. LED nối GPIO 2 qua điện trở 220 ohm. Chưa kiểm chứng điều khiển LED từ trình duyệt do giới hạn của môi trường mô phỏng.
Minh chứng sơ đồ mạch: https://drive.google.com/file/d/1q7BouvANNM43zf0yYfc4xj8vV9g2LR37/view?usp=sharing
Minh chứng Serial Monitor: https://drive.google.com/file/d/1dTdJUc4AiT3NgEx8sxoIC-iJtp3ht6vZ/view?usp=sharing

Bài 5 – MQTT Publish/Subscribe:
ESP32 kết nối Wokwi-GUEST và broker.hivemq.com cổng 1883. Publish nhiệt độ, độ ẩm giả lập mỗi 5 giây lên topic TH3/25112515/sensor, subscribe topic TH3/25112515/control và nhận lại được tin nhắn TEST_SUBSCRIBE qua broker. Chưa kiểm tra bằng MQTT Client độc lập do lỗi kết nối WebSocket trên trình duyệt.
Monitor: https://drive.google.com/file/d/1f-IF2TaoDUdq10LPJ1x3DP5eJFQxha9j/view?usp=sharing

## Cấu trúc thư mục

TH3/
├── Bai1_WiFi_AP_STA/
├── Bai2_BLE_Server/
├── Bai3_ESP_NOW/
│   ├── Transmitter/
│   └── Receiver/
├── Bai4_HTTP_WebServer_LED/
├── Bai5_MQTT/
└── README.md

Mỗi bài là một project PlatformIO gồm src/main.cpp, platformio.ini, wokwi.toml và diagram.json.

## Kết luận

Qua bài thực hành TH3, em đã tìm hiểu và xây dựng chương trình cho năm nội dung giao tiếp trên ESP32 gồm Wi-Fi, BLE, ESP-NOW, HTTP Web Server và MQTT.

Thông qua quá trình thực hiện, em hiểu thêm cách cấu hình Wi-Fi, xây dựng máy chủ, gửi và nhận dữ liệu giữa các thiết bị cũng như sử dụng giao thức MQTT trong hệ thống IoT.

Do sử dụng môi trường mô phỏng Wokwi và không có bộ kit phần cứng thực tế, một số chức năng như BLE, ESP-NOW và điều khiển HTTP qua trình duyệt chưa được kiểm chứng hoàn chỉnh.

Em sẽ tiếp tục kiểm tra và hoàn thiện các chức năng này khi có điều kiện sử dụng phần cứng thực tế.
