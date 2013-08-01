//
//  level.h
//  CocosDragon2
//
//  Created by 170warship on 7/30/13.
//
//

#ifndef __CocosDragon2__level__
#define __CocosDragon2__level__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "NodeCommon.h"
#include "Dragon.h"
USING_NS_CC_EXT;
USING_NS_CC;

//CCNODEOBJECT_LOAD_HEAD(Level, LevelLoader);


class Level : public CCLayer, 
public CCBMemberVariableAssigner, 
public CCBSelectorResolver, 
public CCNodeLoaderListener 
{ 
public: 
    static cocos2d::CCNode* node();
    Dragon* dragon;
     
    virtual bool init(){ 
        if ( !CCLayer::init() ) 
        { 
            return false; 
        }
        return true;
    }
    
    Level(){
        
    }
    
    ~Level(){
        
    }
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName){
        return NULL;
    }
     
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName){
        return NULL;
    }
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode){ 
        if (!strcmp(pMemberVariableName, "dragon")) {
            dragon = (Dragon*)pNode;
        }
        
        return true;
    }
    virtual void onEnter();
    virtual void update(float delta);
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader){}
    
    virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
    CREATE_FUNC(Level); 
};
 
class LevelLoader : public cocos2d::extension::CCLayerLoader { 
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LevelLoader, loader);
protected: 
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Level); 
};



#endif /* defined(__CocosDragon2__level__) */
