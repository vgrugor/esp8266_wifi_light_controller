#include "App/Facades/WebServer/WebServerFacade.h"

WebServerFacade::WebServerFacade()
    : server(AsyncWebServer {80})
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

    WebSocketFacade& webSocket = WebSocketFacade::getInstance();

    this->server.addHandler(webSocket.getWebSocketObject());

    Serial.println(" - finish add handler");
}

void WebServerFacade::initRoutes() {
    Serial.println(" - start init routes");

    this->server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/index.html", "text/html");
    });

    this->server.serveStatic("/", LittleFS, "/");

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
