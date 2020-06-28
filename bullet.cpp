#include "bullet.h"
#include "enemy.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPropertyAnimation>

const QSize Bullet::ms_fixedSize(8, 8);

Bullet::Bullet(QPoint startPos, QPoint targetPoint, int hurt, Enemy *target,
               MainWindow *game, const QPixmap &sprite/* = QPixmap(":/image/bullet.png")*/)
    : m_startPos(startPos)
    , m_targetPos(targetPoint)
    , m_sprite(sprite)
    , m_currentPos(startPos)
    , m_target(target)
    , m_game(game)
    , m_hurt(hurt)
{
}

void Bullet::draw(QPainter *painter) const
{
    painter->drawPixmap(m_currentPos, m_sprite);
}

void Bullet::move()
{
    // 50毫秒内击中敌人
    static const int duration = 50;
    QPropertyAnimation *animation = new QPropertyAnimation(this, "m_currentPos");
    animation->setDuration(duration);
    animation->setStartValue(m_startPos);
    animation->setEndValue(m_targetPos);
    connect(animation, SIGNAL(finished()), this, SLOT(hitTarget()));

    animation->start();
}

void Bullet::hitTarget()//（为了避免伤害溢出）
{
    // 可能多个炮弹击中敌人,而其中一个将其消灭,导致敌人已经消失，后续炮弹再攻击到的敌人就是无效内存区域,造成伤害溢出，因此先判断敌人是否还有效
    if (m_game->enemyList().indexOf(m_target) != -1)
        m_target->getDamage(m_hurt);
    m_game->removedBullet(this);
}

void Bullet::setCurrentPos(QPoint pos)
{
    m_currentPos = pos;
}

QPoint Bullet::currentPos() const
{
    return m_currentPos;
}
