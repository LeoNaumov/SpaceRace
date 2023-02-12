#include "TestScene.h"
#include <cassert>
TestScene::TestScene(SDL_Renderer** r, GameStateManager& GSM)
    :
    GSM(GSM),
    renderer(r)
{
    srand(time(NULL));
    timer.start();
    init = true;
    score1 = 0;
    score2 = 0;
    assert(r!=NULL);
}

void TestScene::logic()
{
    if (init) {
        init = false;
        p1 = new Player1(*renderer);
        p2 = new Player1(*renderer);
        p1->player = 0;
        p2->player = 1;
    }
    if (timer.getTicks() > 300) {
        ents.push_back(new Projectile());
        timer.start();
    }
    p1->logic();
    p2->logic();

    if (p1->posY == 0) {
        score1++;
        std::cout << score1<<"-";
        std::cout << score2 << std::endl;
        p1->posY = 800;
    }
    if (p2->posY == 0) {
        score2++;
        std::cout << score1<<"-";
        std::cout << score2 << std::endl;
        p2->posY = 800;
    }

    for (int i = 0; i < ents.size(); i++) {
        if (ents[i]->rect.x <= -100) {
            ents.erase(ents.begin() +i);
        }
        if (ents[i]->rect.x >= 1000) {
            ents.erase(ents.begin() + i);
        }
    }
}

void TestScene::render()
{
    SDL_Rect temp;
    for (auto& i : ents) {
        i->render(*renderer);
        if (SDL_IntersectRect(&i->rect, &p1->rect, &temp)) {
            p1->posY = 800;
        }
        if (SDL_IntersectRect(&i->rect, &p2->rect, &temp)) {
            p2->posY = 800;
        }
    }
    p1->render();
    p2->render();
}

void TestScene::handleInput(SDL_Event& e)
{
    if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_p: GSM.changeState(new TestScene(renderer, GSM)); break;
        }
    }
    if (!init) {
        p1->handleInput(e);
        p2->handleInput(e);
    }
}

TestScene::~TestScene()
{
    

}