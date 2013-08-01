#ifndef __MAINMENUSCENE_H__
#define __MAINMENUSCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;



class MainMenuScene : public CCLayer,

public CCBMemberVariableAssigner,

public CCBSelectorResolver,

public CCNodeLoaderListener
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    
    virtual bool init();
//
//    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
//    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    
    MainMenuScene(){
        
    }
    
    ~MainMenuScene(){
        
    }
    
//    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MainMenuScene,create);

    

    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget,const char * pSelectorName);

    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget,const char * pSelectorName);

    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode);

    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader);
	
    void pressedPlay(CCObject* sender);
    
    CREATE_FUNC(MainMenuScene);
};

#endif // __MAINMENUSCENE_H__
