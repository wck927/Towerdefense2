#ifndef TOWER_H
#define TOWER_H

#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>

class QPainter;
class Enemy;
class MainWindow;
class QTimer;

class Tower : QObject
{
    Q_OBJECT
public:
    Tower(QPoint pos, MainWindow *game, const QPixmap &sprite = QPixmap(":/image/TT.png"));
    ~Tower();

    void draw(QPainter *painter) const;
    void checkEnemyInRange();
    void targetKilled();
    void attackEnemy();
    void chooseEnemyForAttack(Enemy *enemy);
    void removeBullet();
    void damageEnemy();
    void losingEnemy();

private slots:
    void shootWeapon();

private:
    bool			m_attacking;    //定义塔的攻击
    int				m_Range;	    // 塔的攻击范围
    int				m_damage;		// 塔对敌人造成的伤害
    int				m_Rate;		    // 塔每次攻击的时间间隔
    qreal			m_rotationSprite;//塔的旋转

    Enemy *			m_chooseEnemy;
    MainWindow *	m_game;
    QTimer *		m_RateTimer;

    const QPoint	m_pos;
    const QPixmap	m_sprite;

    static const QSize ms_fixedSize;
};

#endif // TOWER_H
