### 📘 [🇵🇹 leia em Português](./README.pt.md)

### 📡 demo-websockets

Demo project developed as part of the **Backend Engineering Fundamentals** course. The goal is to apply and consolidate knowledge of asynchronous communication using **WebSockets** with **C++** and the **Drogon** framework.

#### 🔧 Technologies Used

* **C++**
* **Drogon (C++ Web Framework)**

#### 🎯 Project Goals

* Explore the implementation of WebSocket servers in C++.
* Develop a backend application capable of handling persistent and bidirectional connections.
* Understand the mechanisms of real-time message exchange between client and server.
* Demonstrate the use of WebSockets with Drogon for modern backend applications.

#### 🧪 Implemented Features

* Establishment of WebSocket connections between client and server.
* Real-time message sending and receiving.
* Session identification and management.
* **Authentication and session filters** for secure communication.

#### 🛠️ Build & Run (with xmake)

To build and run this project using [xmake](https://xmake.io), also with CMake:

```bash
# Install dependencies (make sure Drogon is installed)
xmake f -m release
xmake

# Run the server
xmake run
```
Make sure you have Drogon and its dependencies properly installed on your system before building. For more details, check the [Drogon documentation](https://drogonframework.github.io/drogon-docs/#/).

📌 Notes
This repository has a didactic purpose and serves as a foundation for study and future extensions. Contributions are welcome!
