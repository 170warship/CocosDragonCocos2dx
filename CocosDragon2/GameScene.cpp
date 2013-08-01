//
//  GameScene.cpp
//  CocosDragon2
//
//  Created by 170warship on 7/31/13.
//
//

#include "GameScene.h"
#include "CCBAnimationManager.h"
#include "Bomb.h"
#include "Coin.h"
#include "Dragon.h"
#include "EndCoin.h"
#include "level.h"
static GameSceneInit levelInitInstance;

CCNode*  GameScene::node(){
    CCNodeLoaderLibrary * ccbLib = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    ccbLib->registerCCNodeLoader("GameScene",  GameSceneLoader::loader());
    CCBReader *ccbReader = new CCBReader(ccbLib);
    CCNode *node = ccbReader->readNodeGraphFromFile("GameScene");
    ccbReader->getAnimationManager()->runAnimationsForSequenceNamed("Playing");
    ccbReader->release();
    return node;
}

void GameScene::onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader){
    CCNodeLoaderLibrary *pNodeLoaderLibrary = CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary();
    
    pNodeLoaderLibrary->registerCCNodeLoader("Level", LevelLoader::loader());
    pNodeLoaderLibrary->registerCCNodeLoader("Dragon", DragonLoader::loader());
    pNodeLoaderLibrary->registerCCNodeLoader("Coin", CoinLoader::loader());
    pNodeLoaderLibrary->registerCCNodeLoader("EndCoin", EndCoinLoader::loader());
    
    CCBReader* pReader = new CCBReader(pNodeLoaderLibrary);
    
    
    
    CCNode* PPP = pReader->readNodeGraphFromFile("Level.ccbi");
    levelLayer->addChild(PPP);
}

void GameScene::handleGameOver(){
    CCBReader* pReader = new CCBReader(CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary());
    CCDirector::sharedDirector()->replaceScene(pReader->createSceneWithNodeGraphFromFile("MainMenuScene.ccbi"));
    
}
void GameScene::handleLevelComplete(){
    CCBReader* pReader = new CCBReader(CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary());
    CCDirector::sharedDirector()->replaceScene(pReader->createSceneWithNodeGraphFromFile("MainMenuScene.ccbi"));
    
}