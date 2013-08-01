#include "MainMenuScene.h"
#include "MainMenuSceneLoader.h"
#include "CCBAnimationManager.h"
#include "level.h"
#include "Dragon.h"
#include "Bomb.h"
#include "Coin.h"
#include "EndCoin.h"
#include "GameScene.h"

CCScene* MainMenuScene::scene()
{
    // 'scene' is an autorelease object
    CCNodeLoaderLibrary * ccbLib = CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary();
    ccbLib->registerCCNodeLoader("MainMenuScene", MainMenuSceneLoader::loader());
//    ccbLib->registerCCNodeLoader("Bomb", BombLoader::loader());
    CCBReader *ccbReader = new CCBReader(ccbLib);
    CCScene *scene = ccbReader->createSceneWithNodeGraphFromFile("MainMenuScene.ccbi");
    //CCNode* layer = ccbReader->readNodeGraphFromFile("GameScene.ccbi");
    // 'layer' is an autorelease object
    
//    MainMenuScene *layer = MainMenuScene::create();
//
//    // add layer as a child to scene
//    scene->addChild(layer);
//    ccbReader->getAnimationManager()->runAnimationsForSequenceNamed("Intro");
    ccbReader->release();
//    CCBAnimationManager::runAnimationsForSequenceNamed("Intro");
    // return the scene
    return scene;
}



SEL_MenuHandler MainMenuScene::onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName){

    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "pressedPlay:", MainMenuScene::pressedPlay);

    

}

SEL_CCControlHandler MainMenuScene::onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName){
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "pressedPlay:", MainMenuScene::pressedPlay);

}

bool MainMenuScene::onAssignCCBMemberVariable(cocos2d::CCObject *pTarget, const char *pMemberVariableName, cocos2d::CCNode *pNode){

    return false;

}

void MainMenuScene::onNodeLoaded(cocos2d::CCNode *pNode, cocos2d::extension::CCNodeLoader *pNodeLoader){

    //    CCLOG("node loaded...");

}

void MainMenuScene::pressedPlay(cocos2d::CCObject *sender){

    CCNodeLoaderLibrary *pNodeLoaderLibrary = CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary();

//    pNodeLoaderLibrary->registerCCNodeLoader("Level", LevelLoader::loader());
//    pNodeLoaderLibrary->registerCCNodeLoader("GameScene", GameSceneLoader::loader());
//    pNodeLoaderLibrary->registerCCNodeLoader("Dragon", DragonLoader::loader());
//    pNodeLoaderLibrary->registerCCNodeLoader("Coin", CoinLoader::loader());
//    pNodeLoaderLibrary->registerCCNodeLoader("EndCoin", EndCoinLoader::loader());

    CCBReader* pReader = new CCBReader(pNodeLoaderLibrary);

    

    CCScene* PPP = pReader->createSceneWithNodeGraphFromFile("GameScene.ccbi");
    
    CCDirector::sharedDirector()->replaceScene(PPP);
//    this->addChild(PPP);
    pReader->autorelease();
//    this->addChild(pNode);

}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
//    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
//                                        "CloseNormal.png",
//                                        "CloseSelected.png",
//                                        this,
//                                        menu_selector(MainMenuScene::menuCloseCallback) );
//    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
//
//    // create menu, it's an autorelease object
//    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
//    pMenu->setPosition( CCPointZero );
//    this->addChild(pMenu, 1);
//
//    /////////////////////////////
//    // 3. add your codes below...
//
//    // add a label shows "Hello World"
//    // create and initialize a label
//    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);
//
//    // ask director the window size
//    CCSize size = CCDirector::sharedDirector()->getWinSize();
//
//    // position the label on the center of the screen
//    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );
//
//    // add the label as a child to this layer
//    this->addChild(pLabel, 1);
//
//    // add "HelloWorld" splash screen"
//    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    pSprite->setPosition( ccp(size.width/2, size.height/2) );
//
//    // add the sprite as a child to this layer
//    this->addChild(pSprite, 0);
    
    return true;
}

void MainMenuScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
