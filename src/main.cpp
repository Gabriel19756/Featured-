#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

// This runs when the mod loads
$on_mod(Loaded) {
    log::info("Featured- mod loaded!");
}

// Example: modify LevelInfoLayer to add your custom button
class $modify(LevelInfoLayer) {
    bool init(GJGameLevel* level, bool challenge) {
        if (!LevelInfoLayer::init(level, challenge))
            return false;

        // Create a button
        auto btn = CCMenuItemSpriteExtra::create(
            CCSprite::create("GJ_button_01.png"),
            this,
            menu_selector(LevelInfoLayer::onFeaturedButton)
        );

        btn->setPosition({ 50, 50 });

        auto menu = this->getButtonMenu();
        menu->addChild(btn);

        return true;
    }

    void onFeaturedButton(CCObject*) {
        FLAlertLayer::create(
            "Featured",
            "Your Featured mod button works!",
            "OK"
