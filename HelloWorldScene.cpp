
/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto label = Label::createWithTTF("LEVEL 1", "fonts/Marker Felt.ttf", 15);
    
     if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add Level1.png
    auto sprite = Sprite::create("level1.png");
    if (sprite == nullptr)
    {
        problemLoading("'level1.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }

    mySprite = Sprite::create("bal.png");
    mySprite->setPosition(Vec2((visibleSize.width / 6) + origin.x, (visibleSize.height / 16) + origin.y));
    this->addChild(mySprite);

    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;

}


bool HelloWorld::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {

    CCLOG("onTouchBegan x =%f , y = %f", touch->getLocation().x, touch->getLocation().y);
    auto draw = DrawNode::create();
  


    if (touch->getLocation().x > 350 && touch->getLocation().y < 20) {
        mySprite->setPosition(Vec2(350, 20));
      if ( touch->getLocation().x > 350 == true ) {
            draw->drawSegment(Vec2(140, 20), Vec2(350, 20), 18, Color4F::BLUE);
            this->addChild(draw);
        }
    }



    if (touch->getLocation().y > 130 && touch->getLocation().x > 350) {
        mySprite->setPosition(Vec2(350, 150));
        if (touch->getLocation().y > 130 == true) {
            draw->drawSegment(Vec2(350, 20), Vec2(350, 150), 20, Color4F::BLUE);
            this->addChild(draw);
        }
    }
    if (touch->getLocation().x < 160 && touch->getLocation().y>140) {
        mySprite->setPosition(Vec2(150, 150));
        if (touch->getLocation().x < 160 == true) {
            draw->drawSegment(Vec2(150, 150), Vec2(350, 150), 20, Color4F::BLUE);
             this->addChild(draw);
        }
    }
    if (touch->getLocation().y > 200 && touch->getLocation().x < 160) {
        mySprite->setPosition(Vec2(150, 275));
        if (touch->getLocation().y > 200 == true) {
            draw->drawSegment(Vec2(150, 150), Vec2(150, 275), 20, Color4F::BLUE);
            this->addChild(draw);
        }
    }
    if (touch->getLocation().y > 200 && touch->getLocation().x > 350) {
        mySprite->setPosition(Vec2(350, 275));
        if (touch->getLocation().x > 350 == true) {
            draw->drawSegment(Vec2(150, 275), Vec2(350, 275), 20, Color4F::BLUE);
            this->addChild(draw);   
        }
        return true;
    }

    return true;
}

      




void HelloWorld::menuCloseCallback(Ref* pSender)
{
    // the cocos2d - x game scene and quit the application;
   // Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

  //  EventCustom customEndEvent("game_scene_close_event");
   // _eventDispatcher->dispatchEvent(&customEndEvent);


}

