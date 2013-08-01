//
//  level.cpp
//  CocosDragon2
//
//  Created by 170warship on 7/30/13.
//
//


#include "level.h"
#include "CCTouch.h"

//CCNODEOBJECT_LOAD_BODY(Level, LevelLoader, "Level", "Flying");

static class LevelInit{
public:
    LevelInit(){
        CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary()->registerCCNodeLoader("Level", LevelLoader::loader());
    }
};
static LevelInit levelInitInstance;

CCNode* Level::node(){
    CCNodeLoaderLibrary * ccbLib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
//    ccbLib->registerCCNodeLoader("Level", LevelLoader::loader());
    CCBReader *ccbReader = new CCBReader(ccbLib);
    CCNode *node = ccbReader->readNodeGraphFromFile("Level");
    ccbReader->release();
    return node;
}

void Level::onEnter(){
    CCNode::onEnter();
    this->setTouchEnabled(true);
    this->scheduleUpdate();
//    this->schedule(<#SEL_SCHEDULE selector#>, <#float interval#>, <#unsigned int repeat#>, <#float delay#>)
}


void Level::update(float delta){
    
}

void Level::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    CCTouch* touch = (CCTouch*)pTouches->anyObject();
    CCPoint point = touch->getLocationInView();
    point = CCDirector::sharedDirector()->convertToGL(point);
    
    dragon->setPositionX(point.x);
}

