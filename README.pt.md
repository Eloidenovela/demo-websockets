
### 📘 [🇬🇧 read in English](./README.md)

### 📡 demo-websockets

Projeto de demonstração desenvolvido no contexto do curso de **Fundamentos de Engenharia de Backend**. O objetivo é aplicar e consolidar conhecimentos sobre comunicação assíncrona utilizando **WebSockets** com **C++** e o framework **Drogon**.

#### 🔧 Tecnologias Utilizadas

* **C++**
* **Drogon (Framework Web em C++)**

#### 🎯 Objetivos do Projeto

* Explorar a implementação de servidores WebSocket em C++.
* Desenvolver uma aplicação backend capaz de lidar com conexões persistentes e bidirecionais.
* Compreender os mecanismos de troca de mensagens em tempo real entre cliente e servidor.
* Demonstrar o uso de WebSockets com o Drogon para aplicações backend modernas.


#### 🧪 Funcionalidades Implementadas

* Estabelecimento de conexões WebSocket entre cliente e servidor.
* Envio e receção de mensagens em tempo real.
* Identificação e gestão de sessões.
* **Filtros de autenticação e de sessão** para comunicação segura.

#### 🛠️ Compilação e Execução (com xmake)

Para compilar e executar este projeto usando [xmake](https://xmake.io), também com CMake:

```bash
# Instalar dependências (garanta que o Drogon está instalado)
xmake f -m release
xmake

# Executar o servidor
xmake run
```
Certifica-te de que tens o Drogon e as suas dependências corretamente instaladas no teu sistema antes de compilar. Para mais detalhes, consulta a [documentação oficial do Drogon](https://drogonframework.github.io/drogon-docs/#/).

📌 Observações
Este repositório tem um propósito didático e serve como base para estudos e futuras extensões. Contribuições são bem-vindas!
