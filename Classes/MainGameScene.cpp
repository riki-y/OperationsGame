//
//  MainGameScene.cpp
//  OperationsGame
//
//  Created by 理貴 on 2016/05/06.
//
//

#include "MainGameScene.hpp"
#include "TitleLayer.hpp"
#include <math.h>

USING_NS_CC;


MainGameScene::MainGameScene()
: _num(0),
  _time(0)
{
}

Scene* MainGameScene::createScene()
{
    auto scene = Scene::createWithPhysics();
    auto layer = MainGameScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool MainGameScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(_swallowsTouches);
    touchListener->onTouchBegan = CC_CALLBACK_2(MainGameScene::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(MainGameScene::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(MainGameScene::onTouchEnded, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(MainGameScene::onTouchCancelled, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(MainGameScene::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
    _currentTouchButton = nullptr;
    _commentSprite = nullptr;
    
    _particlePool = ParticleSystemPool::create("plist/explosion.plist", 200);
    _particlePool->retain();
    
    scheduleUpdate();
    
    return true;
}

void MainGameScene::update(float dt)
{
    setTime(getTime() + dt);
    
    if (_hp <= 0) {
        finishGame();
    }
    
    if (getTime() > 5) {
        string delim = " ";
        std::vector<std::string> v = split("2 2 *", delim);
        int i = calculate(v);
        
        if(i > 0) {
            string s = v.at(0)+v.at(2)+v.at(1);
            createComment(s, i);
        }
        
        setTime(0);
    }
}

void MainGameScene::onEnter() {
    Layer::onEnter();
    
    auto v = Vect(-10, -5);
    auto scene = dynamic_cast<Scene*>(this->getParent());
    scene->getPhysicsWorld()->setGravity(v);
//    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    initGameState();
    initBackground();
    createCompany();
    createScope();
    createLeftWall();
    createGround();
    createCeiling();
}

void MainGameScene::initGameState()
{
    _cancelButton = createButton(ButtonSprite::ButtonType::Normal, ButtonSprite::PositionIndex(WINSIZE.width/2 - BUTTON_SIZE*1.5, 100), "del");
    _okButton = createButton(ButtonSprite::ButtonType::Normal, ButtonSprite::PositionIndex(WINSIZE.width/2 + BUTTON_SIZE*1.5, 100), "ok");
    _zeroButton = createButton(ButtonSprite::ButtonType::Normal, ButtonSprite::PositionIndex(WINSIZE.width/2, 100), "0");
    _oneButton = createButton(ButtonSprite::ButtonType::Normal, ButtonSprite::PositionIndex(WINSIZE.width/2 - BUTTON_SIZE*1.5, 120 + BUTTON_SIZE), "1");
    _twoButton = createButton(ButtonSprite::ButtonType::Normal, ButtonSprite::PositionIndex(WINSIZE.width/2, 120 + BUTTON_SIZE), "2");
    _threeButton = createButton(ButtonSprite::ButtonType::Normal, ButtonSprite::PositionIndex(WINSIZE.width/2 + BUTTON_SIZE*1.5, 120 + BUTTON_SIZE), "3");
    _fourButton = createButton(ButtonSprite::ButtonType::Normal, ButtonSprite::PositionIndex(WINSIZE.width/2 - BUTTON_SIZE*1.5, 140 + BUTTON_SIZE*2), "4");
    _fiveButton = createButton(ButtonSprite::ButtonType::Normal, ButtonSprite::PositionIndex(WINSIZE.width/2, 140 + BUTTON_SIZE*2), "5");
    _sixButton = createButton(ButtonSprite::ButtonType::Normal, ButtonSprite::PositionIndex(WINSIZE.width/2 + BUTTON_SIZE*1.5, 140 + BUTTON_SIZE*2), "6");
    _sevenButton = createButton(ButtonSprite::ButtonType::Normal, ButtonSprite::PositionIndex(WINSIZE.width/2 - BUTTON_SIZE*1.5, 160 + BUTTON_SIZE*3), "7");
    _eightButton = createButton(ButtonSprite::ButtonType::Normal, ButtonSprite::PositionIndex(WINSIZE.width/2, 160 + BUTTON_SIZE*3), "8");
    _nineButton = createButton(ButtonSprite::ButtonType::Normal, ButtonSprite::PositionIndex(WINSIZE.width/2 + BUTTON_SIZE*1.5, 160 + BUTTON_SIZE*3), "9");
    
    _oneDigitSprite = createInputCardSprite(InputCardSprite::PositionIndex(4, 685));
    _twoDigitSprite = createInputCardSprite(InputCardSprite::PositionIndex(3, 685));
    _threeDigitSprite = createInputCardSprite(InputCardSprite::PositionIndex(2, 685));
    _fourDigitSprite = createInputCardSprite(InputCardSprite::PositionIndex(1, 685));
    _fiveDigitSprite = createInputCardSprite(InputCardSprite::PositionIndex(0, 685));
}

void MainGameScene::initBackground()
{
    auto background = Sprite::create("background.png");
    background->setAnchorPoint(Point::ZERO);
    background->setPosition(Point::ZERO);
    addChild(background, Z_Background, T_Background);
}

void MainGameScene::createGround()
{
    auto background = getChildByTag(T_Background);
    auto company = getChildByTag(T_Company);
    
    PhysicsMaterial material;
    material.density = 0.5;
    material.restitution = 0.5;
    material.friction = 0.8;
    
    auto body = PhysicsBody::createBox(Size(background->getContentSize().width, 0), material);
    body->setDynamic(false);
    
    auto node = Node::create();
    node->setAnchorPoint(Point::ANCHOR_MIDDLE);
    node->setPhysicsBody(body);
    node->setPosition(Point(background->getContentSize().width / 2, company->getPosition().y - company->getContentSize().height/2));
    addChild(node);
}

void MainGameScene::createCeiling()
{
    auto background = getChildByTag(T_Background);
    
    PhysicsMaterial material;
    material.density = 0.5;
    material.restitution = 0.5;
    material.friction = 0.8;
    
    auto body = PhysicsBody::createBox(Size(background->getContentSize().width, 0), material);
    body->setDynamic(false);
    
    auto node = Node::create();
    node->setAnchorPoint(Point::ANCHOR_MIDDLE);
    node->setPhysicsBody(body);
    node->setPosition(Point(background->getContentSize().width / 2, WINSIZE.height));
    addChild(node);
}

void MainGameScene::createLeftWall()
{
    auto background = getChildByTag(T_Background);
    
    PhysicsMaterial material;
    material.density = 0.5;
    material.restitution = 0.5;
    material.friction = 0.8;
    
    auto body = PhysicsBody::createBox(Size(0, background->getContentSize().height), material);
    body->setDynamic(false);
    
    auto node = Node::create();
    node->setAnchorPoint(Point::ANCHOR_MIDDLE);
    node->setPhysicsBody(body);
    node->setPosition(Point(0, background->getContentSize().height/2));
    addChild(node);
}

void MainGameScene::createComment(std::string operation, int ans)
{
    auto comment = CommentSprite::create(operation, ans);
    comment->setTag(T_Comment);
    
    addChild(comment, Z_Comment);
}

void MainGameScene::createCompany()
{
    auto company = Sprite::create("company.png");
    company->setPosition(Point(company->getContentSize().width/2 + 30, 950));
    company->setTag(T_Company);
    
    PhysicsMaterial material;
    material.density = 0;
    material.restitution = 0;
    material.friction = 0;
    
    auto body = PhysicsBody::createEdgeBox(Size(company->getContentSize().width, company->getContentSize().height));
    body->setDynamic(false);
    body->setGravityEnable(false);
    body->setContactTestBitmask(1);
    company->setPhysicsBody(body);
    
    addChild(company, Z_Company);
    
    // 敵のヒットポイントバー枠の表示
    auto hpBg = Sprite::create("HpEnemyBackground.png");
    hpBg->setPosition(Point(130, 550 + (WINSIZE.height - 660) / 2));
    addChild(hpBg, Z_CompanyHp);
    
    // 敵ヒットポイントバーの表示
    _hpBarForCompany = ProgressTimer::create(Sprite::create("HpEnemyRed.png"));
    _hpBarForCompany->setPosition(Point(hpBg->getContentSize().width / 2, hpBg->getContentSize().height / 2));
    _hpBarForCompany->setType(ProgressTimer::Type::BAR);
    _hpBarForCompany->setMidpoint(Point::ZERO);
    _hpBarForCompany->setBarChangeRate(Point(1,0));
    _hpBarForCompany->setPercentage(10000);
    hpBg->addChild(_hpBarForCompany);
}

void MainGameScene::createScope()
{
    _scope = Sprite::create("transparent.png");
    _scope->setPosition(Point(0,0));
    _scope->setTag(T_Scope);
    
    PhysicsMaterial material;
    material.density = 0;
    material.restitution = 0;
    material.friction = 0;
    
    auto body = PhysicsBody::createCircle(10);
    body->setDynamic(false);
    body->setGravityEnable(false);
    body->setContactTestBitmask(1);
    _scope->setPhysicsBody(body);
    
    addChild(_scope, Z_Scope);
}

ButtonSprite* MainGameScene::createButton(ButtonSprite::ButtonType buttonType, ButtonSprite::PositionIndex positionIndex, std::string str)
{
    auto button = ButtonSprite::create(positionIndex, buttonType, str);
    addChild(button, Z_Button, T_Button);
    
    setTag(button->getGenerateTag(positionIndex));
    
    return button;
}

InputCardSprite* MainGameScene::createInputCardSprite(InputCardSprite::PositionIndex positionIndex)
{
    auto sprite = InputCardSprite::create(positionIndex, InputCardSprite::CardType::Empty, 0);
    addChild(sprite, Z_Sprite, T_Sprite);
    
    return sprite;
}

void MainGameScene::changeInputCardSprites(InputCardSprite::CardType cardType, int num)
{
    if (_fiveDigitSprite->getCardType() == InputCardSprite::CardType::Empty) {
        setNum(getNum()*10 + num);
        
        _fiveDigitSprite->copyCard(_fourDigitSprite);
        _fourDigitSprite->copyCard(_threeDigitSprite);
        _threeDigitSprite->copyCard(_twoDigitSprite);
        _twoDigitSprite->copyCard(_oneDigitSprite);
        _oneDigitSprite->changeCard(cardType, num);
    }
}

void MainGameScene::initInputCardSprite()
{
    setNum(0);
    
    _fiveDigitSprite->initCard();
    _fourDigitSprite->initCard();
    _threeDigitSprite->initCard();
    _twoDigitSprite->initCard();
    _oneDigitSprite->initCard();
}

ButtonSprite* MainGameScene::getTouchButton(Point touchPos, ButtonSprite::PositionIndex withoutPosIndex)
{
    float distance = _cancelButton->getPosition().getDistance(touchPos);
    
    if (distance <= BUTTON_SIZE /2) {
        initInputCardSprite();
        return _cancelButton;
    }
    
    distance = _okButton->getPosition().getDistance(touchPos);
    
    if (distance <= BUTTON_SIZE /2) {
        
        if (_commentSprite != nullptr) {
            if (_commentSprite->equal(getNum())) {
                _commentSprite->removeFromParent();
            }
        }
        
        initInputCardSprite();
        return _okButton;
    }
    
    distance = _zeroButton->getPosition().getDistance(touchPos);
    
    if (distance <= BUTTON_SIZE /2) {
        changeInputCardSprites(InputCardSprite::CardType::Black, 0);
        return _zeroButton;
    }
    
    distance = _oneButton->getPosition().getDistance(touchPos);
    
    if (distance <= BUTTON_SIZE /2) {
        changeInputCardSprites(InputCardSprite::CardType::Red, 1);
        return _oneButton;
    }
    
    distance = _twoButton->getPosition().getDistance(touchPos);
    
    if (distance <= BUTTON_SIZE /2) {
        changeInputCardSprites(InputCardSprite::CardType::Yellow, 2);
        return _twoButton;
    }
    
    distance = _threeButton->getPosition().getDistance(touchPos);
    
    if (distance <= BUTTON_SIZE /2) {
        changeInputCardSprites(InputCardSprite::CardType::Yellow_green, 3);
        return _threeButton;
    }
    
    distance = _fourButton->getPosition().getDistance(touchPos);
    
    if (distance <= BUTTON_SIZE /2) {
        changeInputCardSprites(InputCardSprite::CardType::Green, 4);
        return _fourButton;
    }
    
    distance = _fiveButton->getPosition().getDistance(touchPos);
    
    if (distance <= BUTTON_SIZE /2) {
        changeInputCardSprites(InputCardSprite::CardType::Blue, 5);
        return _fiveButton;
    }
    
    distance = _sixButton->getPosition().getDistance(touchPos);
    
    if (distance <= BUTTON_SIZE /2) {
        changeInputCardSprites(InputCardSprite::CardType::Orange, 6);
        return _sixButton;
    }
    
    distance = _sevenButton->getPosition().getDistance(touchPos);
    
    if (distance <= BUTTON_SIZE /2) {
        changeInputCardSprites(InputCardSprite::CardType::Pink, 7);
        return _sevenButton;
    }
    
    distance = _eightButton->getPosition().getDistance(touchPos);
    
    if (distance <= BUTTON_SIZE /2) {
        changeInputCardSprites(InputCardSprite::CardType::Light_blue, 8);
        return _eightButton;
    }
    
    distance = _nineButton->getPosition().getDistance(touchPos);
    
    if (distance <= BUTTON_SIZE /2) {
        changeInputCardSprites(InputCardSprite::CardType::Purple, 9);
        return _nineButton;
    }
    
    return nullptr;
}

bool MainGameScene::onTouchBegan(Touch* touch, Event* event)
{
    ButtonSprite* touchButton = getTouchButton(touch->getLocation());
    
    if (touchButton) {
        touchButton->changePushButtonImageTexture();
        _currentTouchButton = touchButton;
    } else {
        _scope->setPosition(touch->getLocation());
    }
    
    return true;
}

void MainGameScene::onTouchMoved(Touch* touch, Event* event)
{
    
}

void MainGameScene::onTouchEnded(Touch* touch, Event* event)
{
    if (_currentTouchButton != nullptr) {
        _currentTouchButton->changeButtonImageTexture();
        _currentTouchButton = nullptr;
    }
    
    _scope->setPosition(Point(0,0));
}

bool MainGameScene::onContactBegin(PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    
    if (nodeA != nullptr && nodeB != nullptr) {
        if (nodeA->getTag() != nodeB->getTag()) {
            if (nodeA->getTag() == Tag::T_Comment && nodeB->getTag() == Tag::T_Company) {
                CommentSprite* sprite = (CommentSprite*)nodeA;
                Sprite* company = (Sprite*)nodeB;
                
                showEffect(sprite->getPosition(), _particlePool);
                
                auto act = ProgressFromTo::create(0.5, _hp * 100.f / _maxHp, (_hp - sprite->getAns()) * 100.f / _maxHp);
                _hp = _hp - sprite->getAns();
                _hpBarForCompany->runAction(act);
                
                company->runAction(vibratingAnimation(_hp));
                nodeA->removeFromParent();
            } else if(nodeA->getTag() == Tag::T_Company && nodeB->getTag() == Tag::T_Comment) {
                CommentSprite* sprite = (CommentSprite*)nodeB;
                Sprite* company = (Sprite*)nodeA;

                showEffect(sprite->getPosition(), _particlePool);
                
                auto act = ProgressFromTo::create(0.5, _hp * 100.f / _maxHp, (sprite->getAns() - 400) * 100.f / _maxHp);
                _hp = _hp - sprite->getAns();
                _hpBarForCompany->runAction(act);
                
                company->runAction(vibratingAnimation(_hp));
                nodeB->removeFromParent();
            } else if(nodeA->getTag() == Tag::T_Comment && nodeB->getTag() == Tag::T_Scope) {
                _commentSprite = (CommentSprite*)nodeA;
            } else if(nodeA->getTag() == Tag::T_Scope && nodeB->getTag() == Tag::T_Comment) {
                _commentSprite = (CommentSprite*)nodeB;
            }
        }
    }
    
    return true;
}

void MainGameScene::onTouchCancelled(Touch* touch, Event* event)
{
    onTouchEnded(touch, event);
}

vector<string> MainGameScene::split(const string& s, string delim) {
    vector<string> elms;
    size_t offset = 0;
    while (true) {
        size_t next = s.find_first_of(delim, offset);
        if (next == std::string::npos) {
            elms.push_back(s.substr(offset));
            return elms;
        }
        elms.push_back(s.substr(offset, next - offset));
        offset = next + 1;
    }
}

int MainGameScene::calculate(vector<string> v) {
    if (v.size() != 3) {
        return -1;
    }
    
    int i = 0;
    
    int c1=0, c2=0;
    string c;
    
    for (string s : v) {
        if (i == 0) {
            c1 = atoi(s.c_str());
        } else if ( i == 1) {
            c2 = atoi(s.c_str());
        } else if (i == 2) {
            c = s.c_str();
        }
        
        i++;
    }

    if (c1 < 0 || c2 < 0) {
        return -1;
    }
    
    if (c == "+") {
        return c1 + c2;
    }else if (c == "-") {
        return c1 - c2;
    } else if (c == "*") {
        return c1 * c2;
    }
    
    return -1;
}

void MainGameScene::showEffect(Point point, ParticleSystemPool* particlePool)
{
    auto particle = particlePool->pop();
    particle->setPosition(point);
    this->addChild(particle, Z_Particle, T_Particle);
}

void MainGameScene::finishGame()
{
    unscheduleUpdate();
    
    auto company = getChildByTag(T_Company);
    auto p = company->getPosition();
    
    showEffect(Point(p.x + 10, p.y + 10), _particlePool);
    
    this->runAction(Sequence::create(DelayTime::create(0.5), CallFunc::create([this](){
        auto company = getChildByTag(T_Company);
        auto p = company->getPosition();
        
        showEffect(Point(p.x + 50, p.y + 50), _particlePool);
    }), NULL));
    
    this->runAction(Sequence::create(DelayTime::create(1), CallFunc::create([this](){
        auto company = getChildByTag(T_Company);
        auto p = company->getPosition();
        
        showEffect(Point(p.x + 50, p.y - 50), _particlePool);
    }), NULL));
    
    this->runAction(Sequence::create(DelayTime::create(1.5), CallFunc::create([this](){
        auto company = getChildByTag(T_Company);
        auto p = company->getPosition();
        
        showEffect(Point(p.x - 50, p.y + 50), _particlePool);
    }), NULL));

    this->runAction(Sequence::create(DelayTime::create(2), CallFunc::create([this](){
        auto company = getChildByTag(T_Company);
        auto p = company->getPosition();

        showEffect(Point(p.x - 50, p.y - 50), _particlePool);
        
        company->removeFromParent();
    }), NULL));
    
    this->runAction(Sequence::create(DelayTime::create(2.5), CallFunc::create([this](){
        auto scene = TitleLayer::createScene();
        Director::getInstance()->replaceScene(scene);
    }), NULL));
}

// 振動アニメーション
Spawn* MainGameScene::vibratingAnimation(int afterHp)
{
    auto move = Sequence::create(MoveBy::create(0.025, Point(15, 15)),
                                 MoveBy::create(0.025, Point(-15, -15)),
                                 MoveBy::create(0.025, Point(-15, -15)),
                                 MoveBy::create(0.025, Point(15, 15)),
                                 MoveBy::create(0.025, Point(15, -15)),
                                 MoveBy::create(0.025, Point(-15, 15)),
                                 MoveBy::create(0.025, Point(-15, 15)),
                                 MoveBy::create(0.025, Point(15, -15)),
                                 nullptr);
    
    // ダメージ時に色を赤くする
    Action* tint;
    if (afterHp > 0) {
        // HPが0より大きい場合は、元の色に戻す
        tint = Sequence::create(TintTo::create(0, 255, 0, 0),
                                DelayTime::create(0.2),
                                TintTo::create(0, 255, 255, 255),
                                nullptr);
    } else {
        // HPが0の場合は、赤いままにする
        tint = TintTo::create(0, 255, 0, 0);
    }
    
    return Spawn::create(move, tint, nullptr);
}
