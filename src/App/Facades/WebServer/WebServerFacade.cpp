#include "App/Facades/WebServer/WebServerFacade.h"

WebServerFacade::WebServerFacade()
    : server(AsyncWebServer {80}),
    webSocketFacade(WebSocketFacade {})
{
}

void WebServerFacade::init() {
    Serial.println("Start init web server:");

    this->addWsHandler();

    this->initRoutes();

    this->begin();

    Serial.println("Finish init web server");
}

void WebServerFacade::addWsHandler() {
    Serial.println(" - start add handler");

    this->server.addHandler(this->webSocketFacade.getWebSocketObject());

    Serial.println(" - finish add handler");
}

void WebServerFacade::initRoutes() {
    Serial.println(" - start init routes");

    this->server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", 
            R"rawliteral(
                <!DOCTYPE HTML><html>
                <head>
                <title>ESP Web Server</title>
                <meta name="viewport" content="width=device-width, initial-scale=1">
                <style>
                html {
                    font-family: Arial, Helvetica, sans-serif;
                    text-align: center;
                }
                h1 {
                    font-size: 1.8rem;
                    color: white;
                }
                h2{
                    font-size: 1.5rem;
                    font-weight: bold;
                    color: #143642;
                }
                .topnav {
                    overflow: hidden;
                    background-color: #143642;
                }
                body {
                    margin: 0;
                }
                .content {
                    padding: 30px;
                    max-width: 600px;
                    margin: 0 auto;
                }
                .card {
                    background-color: #F8F7F9;;
                    box-shadow: 2px 2px 12px 1px rgba(140,140,140,.5);
                    padding-top:10px;
                    padding-bottom:20px;
                }
                .button {
                    padding: 15px 50px;
                    font-size: 24px;
                    text-align: center;
                    outline: none;
                    color: #fff;
                    background-color: #0f8b8d;
                    border: none;
                    border-radius: 5px;
                    -webkit-touch-callout: none;
                    -webkit-user-select: none;
                    -khtml-user-select: none;
                    -moz-user-select: none;
                    -ms-user-select: none;
                    user-select: none;
                    -webkit-tap-highlight-color: rgba(0,0,0,0);
                }
                /*.button:hover {background-color: #0f8b8d}*/
                .button:active {
                    background-color: #0f8b8d;
                    box-shadow: 2 2px #CDCDCD;
                    transform: translateY(2px);
                }
                .state {
                    font-size: 1.5rem;
                    color:#8c8c8c;
                    font-weight: bold;
                }
                </style>
                <title>ESP Web Server</title>
                <meta name="viewport" content="width=device-width, initial-scale=1">
                <link rel="icon" href="data:,">
                </head>
                <body>
                <div class="topnav">
                    <h1>ESP WebSocket Server</h1>
                </div>
                <div class="content">
                    <div class="card">
                    <h2>Output - GPIO 2</h2>
                    <p class="state">state: <span id="state">%STATE%</span></p>
                    <p><button id="button" class="button">Toggle</button></p>
                    </div>
                </div>
                <script>
                var gateway = `ws://${window.location.hostname}/ws`;
                var websocket;
                window.addEventListener('load', onLoad);
                function initWebSocket() {
                    console.log('Trying to open a WebSocket connection...');
                    websocket = new WebSocket(gateway);
                    websocket.onopen    = onOpen;
                    websocket.onclose   = onClose;
                    websocket.onmessage = onMessage; // <-- add this line
                }
                function onOpen(event) {
                    console.log('Connection opened');
                }
                function onClose(event) {
                    console.log('Connection closed');
                    setTimeout(initWebSocket, 2000);
                }
                function onMessage(event) {
                    var state;
                    if (event.data == "1"){
                    state = "ON";
                    }
                    else{
                    state = "OFF";
                    }
                    document.getElementById('state').innerHTML = state;
                }
                function onLoad(event) {
                    initWebSocket();
                    initButton();
                }
                function initButton() {
                    document.getElementById('button').addEventListener('click', toggle);
                }
                function toggle(){
                    websocket.send('toggle');
                }
                </script>
                </body>
                </html>
                )rawliteral"
        );
    });

    this->server.on("outdoor/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "-3");
    });

    //this->server.onNotFound(notFound);

    Serial.println(" - finish init routes");
}

void WebServerFacade::begin() {
    Serial.println(" - start web server begin");

    this->server.begin();

    Serial.println(" - finish web server begin");
}

void WebServerFacade::cleanupClients() {
    this->webSocketFacade.cleanupClients();
}
