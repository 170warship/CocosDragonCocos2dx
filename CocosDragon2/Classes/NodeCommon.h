//
//  NodeCommon.h
//  CocosDragon2
//
//  Created by 170warship on 7/30/13.
//
//


#define CCNODEOBJECT_LOAD_HEAD(NODENAME, LOADERNAME  ,  NODENAME_STRING)   \
\
class NODENAME : public CCNode,\
public CCBMemberVariableAssigner,\
public CCBSelectorResolver,\
public CCNodeLoaderListener\
{\
public:\
    static cocos2d::CCNode* node();\
    \
    virtual bool init(){\
        if ( !CCNode::init() )\
        {\
            return false;\
        }\
        return true;\
    }\
    NODENAME(){}\
    ~NODENAME(){}\
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject *pTarget, const char *pSelectorName){return NULL;}\
\
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject *pTarget, const char *pSelectorName){return NULL;}\
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, const char * pMemberVariableName, CCNode * pNode){\
        return false;\
    }\
    virtual void onNodeLoaded(CCNode * pNode, CCNodeLoader * pNodeLoader){}\
    CREATE_FUNC(NODENAME);\
};\
\
class LOADERNAME : public cocos2d::extension::CCNodeLoader {\
public:\
CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LOADERNAME, loader);\
protected:\
CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(NODENAME);\
};\
\



#define  CCNODEOBJECT_LOAD_BODY(NODENAME, LOADERNAME , NODEINITONCENAME, NODENAME_STRING)   static class NODEINITONCENAME{\
public:\
NODEINITONCENAME(){\
CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary()->registerCCNodeLoader(NODENAME_STRING, LOADERNAME::loader());\
}\
};\
static NODEINITONCENAME instance;\
CCNode* NODENAME::node(){\
CCNodeLoaderLibrary * ccbLib = CCNodeLoaderLibrary::sharedCCNodeLoaderLibrary();\
ccbLib->registerCCNodeLoader(NODENAME_STRING, LOADERNAME::loader());\
CCBReader *ccbReader = new CCBReader(ccbLib);\
CCNode *node = ccbReader->readNodeGraphFromFile(NODENAME_STRING);\
ccbReader->release();\
return node;\
}

