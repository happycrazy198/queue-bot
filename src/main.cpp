#include <Geode/Geode.hpp>


using namespace geode::prelude;

#include <Geode/modify/LevelSearchLayer.hpp>
class $modify(MyLevelSearchLayer,LevelSearchLayer) {
    bool init(int p0) {
        if (!LevelSearchLayer::init(p0)) {
            return false;
        }
		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::create("button.png"_spr),
			this,
			menu_selector(MyLevelSearchLayer::onMyButton)
		);
		

		auto menu = (CCMenu *)this->getChildByID("bottom-left-menu");
		menu->addChild(myButton);

		myButton->setID("my-button"_spr);
		myButton->setScaleX(0.600f);
		myButton->setScaleY(0.600f);
		myButton->setPosition({21.000f,135.000f});
		return true;
    }
	void onMyButton(CCLayer* myButton) {
	    auto exitbtn = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
			this,
			menu_selector(MyLevelSearchLayer::onExitBtn)
		);
		auto director = CCDirector::sharedDirector();
		auto size = director->getWinSize();
		auto background = CCSprite::create("GJ_gradientBG.png");
		auto bgWidth = background->getContentSize();
		background->setScaleX(size.width / bgWidth.width);
		background->setScaleY(size.height / bgWidth.height);
		background->setAnchorPoint({0,0});
		background->setZOrder(-1);
		background->setColor({0,102,255});
		exitbtn->setID("exit-btn"_spr);
		CCMenu* menu = CCMenu::create();
		menu->addChild(exitbtn);
		menu->setPosition({27.0f,292.750f});
		myButton->setScaleX(0.600f);
		myButton->setScaleY(0.600f);
		auto scene = CCScene::create();
		scene->addChild(background);
		scene->addChild(menu);
        CCDirector::get()->pushScene(CCTransitionFade::create(.5f, scene));
	}
	void onExitBtn(CCLayer* layer) {
	    CCDirector::sharedDirector()->popSceneWithTransition(0.5f,PopTransition::kPopTransitionFade);
	}
};
