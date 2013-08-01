//
//  MainMenuSceneLoader.h
//  CocoasDragon
//
//  Created by 170warship on 7/25/13.
//
//

#ifndef CocoasDragon_MainMenuSceneLoader_h
#define CocoasDragon_MainMenuSceneLoader_h


#include "MainMenuScene.h"
class MainMenuSceneLoader : public cocos2d::extension::CCLayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MainMenuSceneLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MainMenuScene);
};


#endif
