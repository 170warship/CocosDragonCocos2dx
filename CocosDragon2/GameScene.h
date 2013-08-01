//
//  GameScene.h
//  CocosDragon2
//
//  Created by 170warship on 7/31/13.
//
//

#ifndef __CocosDragon2__GameScene__
#define __CocosDragon2__GameScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "NodeCommon.h"
USING_NS_CC_EXT;
USING_NS_CC;

class  GameScene : public CCLayer,
public CCBMemberVariableAssigner,
public CCBSelectorResolver,
public CCNodeLoaderListener
{
public:
    static cocos2d::CCNode* node();
    CCLayer* levelLayer;
    CCLabelTTF* scoreLabel;
    CCNode* level;
    
    
    virtual bool init(){
        if ( !CCLayer::init() )
        {
            return false;
        }
        return true;
    }
    
    GameScene(){
        
    }
    
    ~GameScene(){
        
    }
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName){
        return NULL;
    }
    
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName){
        return NULL;
    }
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode){
        if (!strcmp(pMemberVariableName, "levelLayer")) {
            levelLayer = (CCLayer*)pNode;
        }
        
        if (!strcmp(pMemberVariableName, "scoreLabel")) {
            scoreLabel = (CCLabelTTF*)pNode;
        }
        
        return true;
    }
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
    
   void handleGameOver();
   void handleLevelComplete();
    CREATE_FUNC( GameScene);
    
    void setScore(int s){
        score = s;
        char* str;
        sprintf(str, "%d", score);
        scoreLabel->setString(str);
    }
private:
    int score;
};

class  GameSceneLoader : public cocos2d::extension::CCLayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD( GameSceneLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD( GameScene);
};

static class GameSceneInit{
public:
    GameSceneInit(){
        CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary()->registerCCNodeLoader("GameScene", GameSceneLoader::loader());
    }
};


#endif /* defined(__CocosDragon2__GameScene__) */
