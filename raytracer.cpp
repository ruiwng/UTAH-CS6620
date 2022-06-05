#include "objects.h"
#include "scene.h"
#include <thread>
#include <mutex>

Node rootNode;
Camera camera;
RenderImage renderImage;
Sphere theSphere;

#define THREAD_COUNT   1

void ShowViewport();

std::atomic<bool> exitFlag(false);
std::atomic<bool> isRendering(false);

void BeginRender() {
    isRendering = true;
}

void StopRender() {
    isRendering = false;
}

std::mutex coordLock;
int currentPixelX = 0;
int currentPixelY = 0;

bool GetPixelCoord(int& x, int& y) {
    std::lock_guard<std::mutex> lk(coordLock);
    if(currentPixelY >= camera.imgHeight) {
        return false;
    }
    x = currentPixelX;
    y = currentPixelY;
    ++currentPixelX;
    if(currentPixelX == camera.imgWidth) {
        currentPixelX = 0;
        ++currentPixelY;
    }
    return true;
}

void RenderThread()
{
    while(!exitFlag) {
        if(isRendering) {

        }
    }
}

int main(int argc, char* argv[]) {
    camera.imgWidth = 1280;
    camera.imgHeight = 720;
    std::vector<std::thread> threadArray;
    for(int i = 0; i < THREAD_COUNT; ++i) {
        threadArray.push_back(std::thread(RenderThread));
    }
    ShowViewport();
    exitFlag = true;
    for(auto& th: threadArray) {
        th.join();
    }
    return 0;
}