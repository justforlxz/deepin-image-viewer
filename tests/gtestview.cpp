#include "gtestview.h"
#define  private public
#include <QKeySequence>
#include <QShortcut>
#include "testapi.h"
#include <QFile>
#include <QDir>
#include "accessibility/ac-desktop-define.h"
gtestview::gtestview()
{

}
TEST_F(gtestview,cpFile)
{
     QFile::copy(":/gif.gif",QApplication::applicationDirPath()+"/gif.gif");
     QFile(QApplication::applicationDirPath()+"/gif.gif").setPermissions( \
                 QFile::WriteUser | QFile::ReadUser |QFile::WriteOther |\
                 QFile::ReadOther |QFile::ReadGroup|QFile::WriteGroup);

     QFile::copy(":/gif2.gif",QApplication::applicationDirPath()+"/gif2.gif");
     QFile(QApplication::applicationDirPath()+"/gif2.gif").setPermissions( \
                 QFile::WriteUser | QFile::ReadUser |QFile::WriteOther |\
                 QFile::ReadOther |QFile::ReadGroup|QFile::WriteGroup);

     QFile::copy(":/ico.ico",QApplication::applicationDirPath()+"/ico.ico");
     QFile(QApplication::applicationDirPath()+"/ico.ico").setPermissions( \
                 QFile::WriteUser | QFile::ReadUser |QFile::WriteOther |\
                 QFile::ReadOther |QFile::ReadGroup|QFile::WriteGroup);

     QFile::copy(":/jpg.jpg",QApplication::applicationDirPath()+"/jpg.jpg");
     QFile(QApplication::applicationDirPath()+"/jpg.jpg").setPermissions( \
                 QFile::WriteUser | QFile::ReadUser |QFile::WriteOther |\
                 QFile::ReadOther |QFile::ReadGroup|QFile::WriteGroup);

     QFile::copy(":/mng.mng",QApplication::applicationDirPath()+"/mng.mng");
     QFile(QApplication::applicationDirPath()+"/mng.mng").setPermissions( \
                 QFile::WriteUser | QFile::ReadUser |QFile::WriteOther |\
                 QFile::ReadOther |QFile::ReadGroup|QFile::WriteGroup);

     QFile::copy(":/png.png",QApplication::applicationDirPath()+"/png.png");
     QFile(QApplication::applicationDirPath()+"/png.png").setPermissions( \
                 QFile::WriteUser | QFile::ReadUser |QFile::WriteOther |\
                 QFile::ReadOther |QFile::ReadGroup|QFile::WriteGroup);

     QFile::copy(":/svg.svg",QApplication::applicationDirPath()+"/svg.svg");
     QFile(QApplication::applicationDirPath()+"/svg.svg").setPermissions( \
                 QFile::WriteUser | QFile::ReadUser |QFile::WriteOther |\
                 QFile::ReadOther |QFile::ReadGroup|QFile::WriteGroup);

     QFile::copy(":/tif.tif",QApplication::applicationDirPath()+"/tif.tif");
     QFile(QApplication::applicationDirPath()+"/tif.tif").setPermissions( \
                 QFile::WriteUser | QFile::ReadUser |QFile::WriteOther |\
                 QFile::ReadOther |QFile::ReadGroup|QFile::WriteGroup);

     QFile::copy(":/wbmp.wbmp",QApplication::applicationDirPath()+"/wbmp.wbmp");
     QFile(QApplication::applicationDirPath()+"/wbmp.wbmp").setPermissions( \
                 QFile::WriteUser | QFile::ReadUser |QFile::WriteOther |\
                 QFile::ReadOther |QFile::ReadGroup|QFile::WriteGroup);

     QFile::copy(":/dds.dds",QApplication::applicationDirPath()+"/dds.dds");
     QFile(QApplication::applicationDirPath()+"/dds.dds").setPermissions( \
                 QFile::WriteUser | QFile::ReadUser |QFile::WriteOther |\
                 QFile::ReadOther |QFile::ReadGroup|QFile::WriteGroup);

     QDir a(QApplication::applicationDirPath());
     a.mkdir("test");
     QFile::copy(":/jpg.jpg",QApplication::applicationDirPath()+"/test/jpg.jpg");
     QFile(QApplication::applicationDirPath()+"/test/jpg.jpg").setPermissions( \
                 QFile::WriteUser | QFile::ReadUser |QFile::WriteOther |\
                 QFile::ReadOther |QFile::ReadGroup|QFile::WriteGroup);
}


//主窗体
TEST_F(gtestview, mainwindow)
{
    DApplicationSettings saveTheme;
    //4.将时间写入QDataStream
    QDateTime wstime = QDateTime::currentDateTime();
    QString teststr = wstime.toString("yyyy-MM-dd hh:mm:ss");
    bool newflag = true;
    CommandLine::instance()->processOption(wstime, newflag);

    if(!m_frameMainWindow)
    {
        m_frameMainWindow = CommandLine::instance()->getMainWindow();
    }
    QTest::qWait(1000);

    ViewPanel *panel = m_frameMainWindow->findChild<ViewPanel *>(VIEW_PANEL_WIDGET);
    if(panel){
        // 打开保存绘制的 tif
        QString TriangleItemPath = QApplication::applicationDirPath() + "/tif.tif";
        drogPathtoWidget(panel,TriangleItemPath);
    }

    m_frameMainWindow->setWindowRadius(18);
    m_frameMainWindow->setBorderWidth(0);
    m_frameMainWindow->show();
    QTest::mousePress(m_frameMainWindow, Qt::LeftButton);
    QTest::mouseRelease(m_frameMainWindow, Qt::LeftButton);
    QTest::mouseClick(m_frameMainWindow, Qt::LeftButton);
    QTest::mouseMove(m_frameMainWindow, QPoint(190,50));
    QTest::mouseDClick(m_frameMainWindow,Qt::LeftButton);

//    m_frameMainWindow->OpenImage(m_GIFPath);





    QTest::keyClick(m_frameMainWindow, Qt::Key_Right, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Up, Qt::ControlModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Up, Qt::ControlModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Up, Qt::ControlModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Down, Qt::ControlModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Down, Qt::ControlModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Down, Qt::ControlModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Right, Qt::NoModifier, 200);

    QTest::keyClick(m_frameMainWindow, Qt::Key_Left, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Left, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Left, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Left, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Left, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Left, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Left, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Left, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Left, Qt::NoModifier, 200);


    QTest::keyClick(m_frameMainWindow, Qt::Key_Right, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Right, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Right, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Right, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Right, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Right, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Right, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Right, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Left, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Right, Qt::NoModifier, 200);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Up, Qt::ControlModifier, 500);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Up, Qt::ControlModifier, 500);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Up, Qt::ControlModifier, 500);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Down, Qt::ControlModifier, 500);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Down, Qt::ControlModifier, 500);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Down, Qt::ControlModifier, 500);

    QTest::keyClick(m_frameMainWindow, Qt::Key_F11, Qt::NoModifier, 2000);//
    int index=0;
    while(index++<10)
        QTest::keyClick(m_frameMainWindow, Qt::Key_Plus, Qt::ControlModifier, 50);
    while(index-->0)
        QTest::keyClick(m_frameMainWindow, Qt::Key_Minus, Qt::ControlModifier, 50);
    QTest::mouseMove(m_frameMainWindow, QPoint(1000,1075),1000);
    QTest::mouseMove(m_frameMainWindow, QPoint(200,500),1000);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Escape, Qt::NoModifier, 1000);

}
TEST_F(gtestview, sliderShow)
{
    if(!m_frameMainWindow)
    {
        m_frameMainWindow = CommandLine::instance()->getMainWindow();
    }
    m_frameMainWindow->showNormal();
    m_frameMainWindow->resize(800,600);
    QTest::keyClick(m_frameMainWindow, Qt::Key_R, Qt::ControlModifier | Qt::ShiftModifier, 100);
    QTest::keyClick(m_frameMainWindow, Qt::Key_R, Qt::ControlModifier , 500);
    QTest::keyClick(m_frameMainWindow, Qt::Key_F5, Qt::NoModifier, 5000);

    QTest::mouseMove(m_frameMainWindow, QPoint(1000,1075),1000);
    QTest::mouseMove(m_frameMainWindow, QPoint(200,500),1000);

    QTest::mousePress(m_frameMainWindow, Qt::LeftButton,Qt::NoModifier,QPoint(100,1020),300);
    QTest::mouseRelease(m_frameMainWindow, Qt::LeftButton,Qt::NoModifier,QPoint(200,1020),300);
    QTest::mouseClick(m_frameMainWindow, Qt::LeftButton,Qt::NoModifier,QPoint(300,1020),300);
    QTest::mouseMove(m_frameMainWindow, QPoint(400,1020),300);
    QTest::mouseDClick(m_frameMainWindow,Qt::LeftButton,Qt::NoModifier,QPoint(500,1020),300);
    QTest::keyClick(m_frameMainWindow, Qt::Key_I, Qt::ControlModifier , 500);

    QTest::mouseClick(m_frameMainWindow, Qt::RightButton,Qt::NoModifier,QPoint(300,1020),300);

    QTest::mouseClick(m_frameMainWindow, Qt::MidButton,Qt::NoModifier,QPoint(300,1020),300);


    QTest::keyClick(m_frameMainWindow, Qt::Key_Escape, Qt::NoModifier, 500);

    m_frameMainWindow->hide();
    m_frameMainWindow->showNormal();


}
TEST_F(gtestview, infoWidget)
{
    if(!m_frameMainWindow)
    {
        m_frameMainWindow = CommandLine::instance()->getMainWindow();
    }
    QTest::keyClick(m_frameMainWindow, Qt::Key_Escape, Qt::NoModifier, 500);
    m_frameMainWindow->resize(800,600);
    QTest::keyClick(m_frameMainWindow, Qt::Key_I, Qt::ControlModifier , 500);

    QTest::keyClick(m_frameMainWindow, Qt::Key_Escape, Qt::NoModifier, 50);
}

TEST_F(gtestview, iconRotatePic)
{
    if(!m_frameMainWindow)
    {
        m_frameMainWindow = CommandLine::instance()->getMainWindow();
    }
    DIconButton *m_adaptImageBtn=m_frameMainWindow->findChild<DIconButton *>(ADAPT_BUTTON);
    DIconButton *m_adaptScreenBtn=m_frameMainWindow->findChild<DIconButton *>(ADAPT_SCREEN_BUTTON);
    DIconButton *m_preButton=m_frameMainWindow->findChild<DIconButton *>(PRE_BUTTON);
    DIconButton *m_nextButton=m_frameMainWindow->findChild<DIconButton *>(NEXT_BUTTON);
    DIconButton *m_rotateRBtn=m_frameMainWindow->findChild<DIconButton *>(CLOCKWISE_ROTATION);
    DIconButton *m_rotateLBtn=m_frameMainWindow->findChild<DIconButton *>(COUNTER_CLOCKWISE_ROTATION);
    DIconButton *m_trashBtn=m_frameMainWindow->findChild<DIconButton *>(TRASH_BUTTON);
    ViewPanel *panel = m_frameMainWindow->findChild<ViewPanel *>(VIEW_PANEL_WIDGET);
    if(panel){
        m_adaptImageBtn->click();
        QTest::qWait(100);
        m_adaptScreenBtn->click();
        QTest::qWait(100);
        m_preButton->click();
        QTest::qWait(100);
        m_nextButton->click();
        QTest::qWait(100);
        m_rotateRBtn->click();
        QTest::qWait(100);
        m_rotateLBtn->click();
        QTest::qWait(100);
        m_nextButton->click();
        QTest::qWait(100);
        m_adaptScreenBtn->click();
        QTest::qWait(100);
        m_preButton->click();
        QTest::qWait(100);
        m_nextButton->click();
        QTest::qWait(100);
        m_rotateRBtn->click();
        QTest::qWait(100);
        m_rotateLBtn->click();
        QTest::qWait(100);
        m_nextButton->click();
        QTest::qWait(100);
        m_adaptScreenBtn->click();
        QTest::qWait(100);
        m_preButton->click();
        QTest::qWait(100);
        m_nextButton->click();
        QTest::qWait(100);
        m_rotateRBtn->click();
        QTest::qWait(100);
        m_rotateLBtn->click();
        QTest::qWait(100);
        m_nextButton->click();
        QTest::qWait(100);
        m_adaptScreenBtn->click();
        QTest::qWait(100);
        m_preButton->click();
        QTest::qWait(100);
        m_nextButton->click();
        QTest::qWait(100);
        m_rotateRBtn->click();
        QTest::qWait(100);
        m_rotateLBtn->click();
        QTest::qWait(100);
        m_nextButton->click();
        QTest::qWait(100);
        m_adaptScreenBtn->click();
        QTest::qWait(100);
        m_preButton->click();
        QTest::qWait(100);
        m_nextButton->click();
        QTest::qWait(100);
        m_rotateRBtn->click();
        QTest::qWait(100);
        m_rotateLBtn->click();
        QTest::qWait(100);
        m_nextButton->click();
        QTest::qWait(100);
        m_adaptScreenBtn->click();
        QTest::qWait(100);
        m_preButton->click();
        QTest::qWait(100);
        m_nextButton->click();
        QTest::qWait(100);
        m_rotateRBtn->click();
        QTest::qWait(100);
        m_rotateLBtn->click();
        QTest::qWait(1000);
        m_nextButton->click();
        QTest::qWait(100);



    }

}

TEST_F(gtestview, onlyonePic)
{
    if(!m_frameMainWindow)
    {
        m_frameMainWindow = CommandLine::instance()->getMainWindow();
    }
    //    SLIDE_SHOW_WIDGET
    ViewPanel *panel = m_frameMainWindow->findChild<ViewPanel *>(VIEW_PANEL_WIDGET);
    if(panel){
        // 打开 jpg
        QString TriangleItemPath = QApplication::applicationDirPath() + "/test/jpg.jpg";
        drogPathtoWidget(panel,TriangleItemPath);
        QTest::qWait(2000);

//        QTest::keyClick(m_frameMainWindow, Qt::Key_F5, Qt::NoModifier, 2000);
//        QTest::keyClick(m_frameMainWindow, Qt::Key_Escape, Qt::NoModifier, 500);
//        m_frameMainWindow->hide();
//        m_frameMainWindow->showMaximized();



        DIconButton *m_adaptImageBtn=m_frameMainWindow->findChild<DIconButton *>(ADAPT_BUTTON);
        DIconButton *m_adaptScreenBtn=m_frameMainWindow->findChild<DIconButton *>(ADAPT_SCREEN_BUTTON);
//        DIconButton *m_preButton=m_frameMainWindow->findChild<DIconButton *>(PRE_BUTTON);
//        DIconButton *m_nextButton=m_frameMainWindow->findChild<DIconButton *>(NEXT_BUTTON);
        DIconButton *m_rotateRBtn=m_frameMainWindow->findChild<DIconButton *>(CLOCKWISE_ROTATION);
        DIconButton *m_rotateLBtn=m_frameMainWindow->findChild<DIconButton *>(COUNTER_CLOCKWISE_ROTATION);
        DIconButton *m_trashBtn=m_frameMainWindow->findChild<DIconButton *>(TRASH_BUTTON);

        m_adaptImageBtn->click();
        QTest::qWait(100);
        m_adaptScreenBtn->click();
        QTest::qWait(100);
        m_rotateRBtn->click();
        QTest::qWait(100);
        m_rotateLBtn->click();
        QTest::qWait(100);


//        QTest::keyClick(m_frameMainWindow, Qt::Key_F11, Qt::NoModifier, 2000);//
        int index=0;
        while(index++<10)
            QTest::keyClick(m_frameMainWindow, Qt::Key_Plus, Qt::ControlModifier, 50);
        while(index-->0)
            QTest::keyClick(m_frameMainWindow, Qt::Key_Minus, Qt::ControlModifier, 50);

        m_frameMainWindow->showFullScreen();
        QTest::keyClick(m_frameMainWindow, Qt::Key_Escape, Qt::NoModifier, 500);
        m_frameMainWindow->showNormal();

        QTest::keyClick(m_frameMainWindow, Qt::Key_F5, Qt::NoModifier, 500);
        QTest::keyClick(m_frameMainWindow, Qt::Key_Escape, Qt::NoModifier, 500);
        m_frameMainWindow->showNormal();

        m_trashBtn->click();
        QTest::qWait(100);
    }

}

TEST_F(gtestview, sliderSvg)
{
    if(!m_frameMainWindow)
    {
        m_frameMainWindow = CommandLine::instance()->getMainWindow();
    }
    //    SLIDE_SHOW_WIDGET
    ViewPanel *panel = m_frameMainWindow->findChild<ViewPanel *>(VIEW_PANEL_WIDGET);
    if(panel){
        // 打开 svg
        QString TriangleItemPath = QApplication::applicationDirPath() + "/svg.svg";
        drogPathtoWidget(panel,TriangleItemPath);
    }
    QTest::keyClick(m_frameMainWindow, Qt::Key_F5, Qt::NoModifier, 2000);
    QTest::keyClick(m_frameMainWindow, Qt::Key_Escape, Qt::NoModifier, 500);
    m_frameMainWindow->hide();
    m_frameMainWindow->showMaximized();
    m_frameMainWindow->showNormal();
}
TEST_F(gtestview, MyImageListWidget)
{
    if(!m_frameMainWindow)
    {
        m_frameMainWindow = CommandLine::instance()->getMainWindow();
    }
    MyImageListWidget *widget = m_frameMainWindow->findChild<MyImageListWidget *>(IMAGE_LIST_WIDGET);
    ASSERT_NE(widget,nullptr);

    QTestEventList e;
    e.addMouseMove(QPoint(100,30), 200);
    //    e.addKeyPress(Qt::Key_Shift, Qt::NoModifier, 50);
    e.addMousePress(Qt::LeftButton, Qt::NoModifier, QPoint(100,30), 200);
    e.addMouseMove(QPoint(150,30), 200);
    e.addMouseMove(QPoint(200,30), 200);
    //    e.addKeyRelease(Qt::Key_Shift, Qt::NoModifier, 200);
    e.addMouseRelease(Qt::LeftButton, Qt::NoModifier, QPoint(250,30), 200);
    e.simulate(widget);

    e.clear();


}
TEST_F(gtestview, testDrag)
{
    if(!m_frameMainWindow)
    {
        m_frameMainWindow = CommandLine::instance()->getMainWindow();
    }
    ViewPanel *panel = m_frameMainWindow->findChild<ViewPanel *>(VIEW_PANEL_WIDGET);
    if(panel){
        // 打开图片
//        QString TriangleItemPath = QApplication::applicationDirPath() + "/jpg.jpg";
//        drogPathtoWidget(panel,TriangleItemPath);

//        QString TriangleItemPath1 = QApplication::applicationDirPath() + "/mng.mng";
//        drogPathtoWidget(panel,TriangleItemPath1);

//        QString TriangleItemPath2 = QApplication::applicationDirPath() + "/png.png";
//        drogPathtoWidget(panel,TriangleItemPath2);

        QTest::qWait(500);

    }
}
//设置背景颜色
TEST_F(gtestview, ViewerThemeManager)
{
//     dApp->viewerTheme->setCurrentTheme(ViewerThemeManager::Light);

     dApp->viewerTheme->setCurrentTheme(ViewerThemeManager::Dark);
     dApp->viewerTheme->setCurrentTheme(ViewerThemeManager::Light);
    /*module*/
    //    m_viewPanel=new ViewPanel(nullptr);
    //    m_viewPanel->show();
    //    m_viewPanel->refreshPixmap("/usr/share/wallpapers/deepin/Hummingbird_by_Shu_Le.jpg");

    //    QString filter = tr("All images");

    //    filter.append('(');
    //    filter.append(utils::image::supportedImageFormats().join(" "));
    //    filter.append(')');


}


TEST_F(gtestview, m_ImageLoader)
{
    //    m_ImageLoader=new ImageLoader(NULL,QStringList(DDSPATH),m_JPGPath);
}
TEST_F(gtestview, setWallPaper)
{
    QString TriangleItemPath = QApplication::applicationDirPath() + "/jpg.jpg";

    dApp->wpSetter->setWallpaper(TriangleItemPath);

}
TEST_F(gtestview, m_pushbutton)
{
    m_pushbutton=new PushButton();
    m_pushbutton->show();
    m_pushbutton->normalPic();
    m_pushbutton-> hoverPic() ;
    m_pushbutton-> pressPic() ;
    m_pushbutton-> disablePic() ;
    m_pushbutton-> checkedPic() ;
    m_pushbutton-> text() ;
    m_pushbutton-> normalColor() ;
    m_pushbutton-> hoverColor() ;
    m_pushbutton-> pressColor() ;
    m_pushbutton-> disableColor() ;
    m_pushbutton-> getSpacing() ;
    m_pushbutton-> setSpacing(11);
    m_pushbutton-> getChecked() ;
    m_pushbutton-> setToolTip("TEST");
    m_pushbutton-> setChecked(false);
    m_pushbutton-> setNormalPic(m_JPGPath);
    m_pushbutton-> setHoverPic(m_JPGPath);
    m_pushbutton-> setPressPic(m_JPGPath);
    m_pushbutton-> setDisablePic(m_JPGPath);
    m_pushbutton-> setCheckedPic(m_JPGPath);
    m_pushbutton-> setText("test");
    m_pushbutton-> setNormalColor(QColor(120,111,150));
    m_pushbutton-> setHoverColor(QColor(120,180,150));
    m_pushbutton-> setPressColor(QColor(120,20,150));
    m_pushbutton-> setDisableColor(QColor(120,123,150));

    m_pushbutton-> setToolTip("TEST");
    m_pushbutton-> setChecked(true);
    m_pushbutton-> setNormalPic(m_JPGPath);
    m_pushbutton-> setHoverPic(m_JPGPath);
    m_pushbutton-> setPressPic(m_JPGPath);
    m_pushbutton-> setDisablePic(m_JPGPath);
    m_pushbutton-> setCheckedPic(m_JPGPath);
    m_pushbutton-> setText("test");
    m_pushbutton-> setNormalColor(QColor(120,111,150));
    m_pushbutton-> setHoverColor(QColor(120,180,150));
    m_pushbutton-> setPressColor(QColor(120,20,150));
    m_pushbutton-> setDisableColor(QColor(120,123,150));

    QTest::mousePress(m_pushbutton, Qt::LeftButton);
    QTest::mouseRelease(m_pushbutton, Qt::LeftButton);
    QTest::mouseClick(m_pushbutton, Qt::LeftButton);
    QTest::mouseMove(m_pushbutton, QPoint(50,50),200);
        QTest::keyClick(m_pushbutton, Qt::Key_Escape, Qt::ShiftModifier, 1000);
    QTest::mouseDClick(m_pushbutton,Qt::LeftButton);
}
TEST_F(gtestview, m_returnButton)
{
    m_returnButton=new ReturnButton();
    m_returnButton->show();
    m_returnButton->normalPic();
    m_returnButton-> hoverPic() ;
    m_returnButton-> pressPic() ;
    m_returnButton-> disablePic() ;
    m_returnButton-> checkedPic() ;
    m_returnButton-> text() ;
    m_returnButton-> normalColor() ;
    m_returnButton-> hoverColor() ;
    m_returnButton-> pressColor() ;
    m_returnButton-> disableColor() ;
    m_returnButton-> getSpacing() ;
    m_returnButton-> setSpacing(11);
    m_returnButton-> getChecked() ;
    m_returnButton-> setToolTip("TEST");
    m_returnButton-> setChecked(false);
    m_returnButton-> setNormalPic(m_JPGPath);
    m_returnButton-> setHoverPic(m_JPGPath);
    m_returnButton-> setPressPic(m_JPGPath);
    m_returnButton-> setDisablePic(m_JPGPath);
    m_returnButton-> setCheckedPic(m_JPGPath);
    m_returnButton-> setText("test");
    m_returnButton-> setNormalColor(QColor(120,111,150));
    m_returnButton-> setHoverColor(QColor(120,180,150));
    m_returnButton-> setPressColor(QColor(120,20,150));
    m_returnButton-> setDisableColor(QColor(120,123,150));

    m_returnButton-> setToolTip("TEST");
    m_returnButton-> setChecked(true);
    m_returnButton-> setNormalPic(m_JPGPath);
    m_returnButton-> setHoverPic(m_JPGPath);
    m_returnButton-> setPressPic(m_JPGPath);
    m_returnButton-> setDisablePic(m_JPGPath);
    m_returnButton-> setCheckedPic(m_JPGPath);
    m_returnButton-> setText("test");
    m_returnButton-> setNormalColor(QColor(120,111,150));
    m_returnButton-> setHoverColor(QColor(120,180,150));
    m_returnButton-> setPressColor(QColor(120,20,150));
    m_returnButton-> setDisableColor(QColor(120,123,150));

    QTest::mousePress(m_returnButton, Qt::LeftButton);
    QTest::mouseRelease(m_returnButton, Qt::LeftButton);
    QTest::mouseClick(m_returnButton, Qt::LeftButton);
    QTest::mouseMove(m_returnButton, QPoint(50,50),200);
    QTest::keyClick(m_returnButton, Qt::Key_Escape, Qt::ShiftModifier, 1000);
    QTest::mouseDClick(m_returnButton,Qt::LeftButton);

}
TEST_F(gtestview, m_bottomToolbar)
{
    /*frame*/
    m_bottomToolbar =new BottomToolbar(nullptr);
    m_bottomToolbar->show();
    QTest::mousePress(m_bottomToolbar, Qt::LeftButton);
    QTest::mouseRelease(m_bottomToolbar, Qt::LeftButton);
    QTest::mouseClick(m_bottomToolbar, Qt::LeftButton);
    QTest::mouseMove(m_bottomToolbar, QPoint(50,50));
    //        QTest::keyClick(m_bottomToolbar, Qt::Key_Escape, Qt::ShiftModifier, 200);
    QTest::mouseDClick(m_bottomToolbar,Qt::LeftButton);
}
TEST_F(gtestview, m_frameMainWidget)
{
    m_frameMainWidget=new MainWidget(false,nullptr);
    m_frameMainWidget->show();
    QTest::mousePress(m_frameMainWidget, Qt::LeftButton);
    QTest::mouseRelease(m_frameMainWidget, Qt::LeftButton);
    QTest::mouseClick(m_frameMainWidget, Qt::LeftButton);
    QTest::mouseMove(m_frameMainWidget, QPoint(230,50));
    //        QTest::keyClick(m_frameMainWidget, Qt::Key_Escape, Qt::ShiftModifier, 200);
    QTest::mouseDClick(m_frameMainWidget,Qt::LeftButton);
}
TEST_F(gtestview, RenameDialog)
{
    m_renameDialog=new RenameDialog(nullptr);
    m_renameDialog->show();
    QTest::mousePress(m_renameDialog, Qt::LeftButton);
    QTest::mouseRelease(m_renameDialog, Qt::LeftButton);
    QTest::mouseClick(m_renameDialog, Qt::LeftButton);
    QTest::mouseMove(m_renameDialog, QPoint(190,100));
    //        QTest::keyClick(m_renameDialog, Qt::Key_Escape, Qt::ShiftModifier, 200);
    QTest::mouseDClick(m_renameDialog,Qt::LeftButton);

    m_renameDialog->onThemeChanged(ViewerThemeManager::Light);

    m_renameDialog->onThemeChanged(ViewerThemeManager::Dark);
}
TEST_F(gtestview, TopToolbar)
{
    m_topoolBar=new TopToolbar(false,nullptr);
    m_topoolBar->show();
    QTest::mousePress(m_topoolBar, Qt::LeftButton);
    QTest::mouseRelease(m_topoolBar, Qt::LeftButton);
    QTest::mouseClick(m_topoolBar, Qt::LeftButton);
    QTest::mouseMove(m_topoolBar, QPoint(190,160));
    //        QTest::keyClick(m_topoolBar, Qt::Key_Escape, Qt::ShiftModifier, 200);
    QTest::mouseDClick(m_topoolBar,Qt::LeftButton);

    m_topoolBar->setMiddleContent("test");
    m_topoolBar->setTitleBarTransparent(true);
    m_topoolBar->setTitleBarTransparent(false);
    //        QTest::keyClick(m_topoolBar, Qt::Key_Escape, Qt::ShiftModifier, 200);
    QTest::mouseDClick(m_topoolBar,Qt::LeftButton);
}
TEST_F(gtestview, LockWidget)
{
    m_lockWidget=new LockWidget("","");
    m_lockWidget->show();
    QTest::mousePress(m_lockWidget, Qt::LeftButton);
    QTest::mouseRelease(m_lockWidget, Qt::LeftButton);
    QTest::mouseClick(m_lockWidget, Qt::LeftButton);
    QTest::mouseMove(m_lockWidget, QPoint(50,160));
    //        QTest::keyClick(m_lockWidget, Qt::Key_Escape, Qt::ShiftModifier, 200);
    QTest::mouseDClick(m_lockWidget,Qt::LeftButton);
}
TEST_F(gtestview, ThumbnailWidget)
{
    m_thumbnailWidget=new ThumbnailWidget(m_SVGPath,m_SVGPath);
    m_thumbnailWidget->show();
    QTest::mousePress(m_thumbnailWidget, Qt::LeftButton);
    QTest::mouseRelease(m_thumbnailWidget, Qt::LeftButton);
    QTest::mouseClick(m_thumbnailWidget, Qt::LeftButton);
    QTest::mouseMove(m_thumbnailWidget, QPoint(130,160));
    //        QTest::keyClick(m_thumbnailWidget, Qt::Key_Escape, Qt::ShiftModifier, 200);
    QTest::mouseDClick(m_thumbnailWidget,Qt::LeftButton);
}
TEST_F(gtestview, NavigationWidget)
{
    m_navigationWidget=new NavigationWidget();
    m_navigationWidget->show();
    QTest::mousePress(m_navigationWidget, Qt::LeftButton);
    QTest::mouseRelease(m_navigationWidget, Qt::LeftButton);
    QTest::mouseClick(m_navigationWidget, Qt::LeftButton);
    QTest::mouseMove(m_navigationWidget, QPoint(700,160));
    //        QTest::keyClick(m_navigationWidget, Qt::Key_Escape, Qt::ShiftModifier, 200);
    QTest::mouseDClick(m_navigationWidget,Qt::LeftButton);
}
TEST_F(gtestview, ImageIconButton)
{
    m_ImageIconButton1=new ImageIconButton();
    m_ImageIconButton1->setPropertyPic(m_SVGPath,QVariant(),m_SVGPath,m_SVGPath,m_SVGPath,m_SVGPath);
    m_ImageIconButton1->show();
    m_ImageIconButton2=new ImageIconButton(m_SVGPath,m_SVGPath,m_SVGPath,m_SVGPath);
    m_ImageIconButton2->setPropertyPic(m_SVGPath,QVariant(),m_SVGPath,m_SVGPath,m_SVGPath,m_SVGPath);
    m_ImageIconButton2->show();
    m_ImageIconButton2->setAutoChecked(false);
    m_ImageIconButton2->setTransparent(false);
}
TEST_F(gtestview, ImageInfoWidget)
{
    m_ImageInfoWidget= new ImageInfoWidget("","");
    m_ImageInfoWidget->setImagePath(m_JPGPath);
    m_ImageInfoWidget->onExpandChanged(false);
    m_ImageInfoWidget->contentHeight();
}
TEST_F(gtestview, ImageView)
{
    m_ImageView=new ImageView();
    m_ImageView->setImage(m_JPGPath);
    m_ImageView->show();
    m_ImageView->cachePixmap(m_JPGPath);
    m_ImageView->fitWindow();
    m_ImageView->fitWindow_btnclicked();
    m_ImageView->fitImage();
    m_ImageView->rotateClockWise();
    m_ImageView->rotateCounterclockwise();

    m_ImageView->autoFit();
    m_ImageView->titleBarControl();
    m_ImageView->image();
    m_ImageView->windowRelativeScale();
    m_ImageView->windowRelativeScale_origin();
    m_ImageView->imageRect();
    m_ImageView->path();

    m_ImageView->visibleImageRect();
    m_ImageView->isWholeImageVisible();
    m_ImageView->isFitImage();
    m_ImageView->isFitWindow();
    m_ImageView->rotatePixCurrent();

    //        m_ImageView->showPixmap(m_JPGPath);
    //        m_ImageView->loadPictureByType(m_ImageView->judgePictureType(m_JPGPath),m_JPGPath);
    emit m_ImageView->clicked();
    emit m_ImageView->doubleClicked();
    emit m_ImageView->mouseHoverMoved();
    emit m_ImageView->scaled(200);
    emit m_ImageView->transformChanged();
    emit m_ImageView->showScaleLabel();
    emit m_ImageView->nextRequested();
    emit m_ImageView->previousRequested();
    emit m_ImageView->disCheckAdaptImageBtn();
    emit m_ImageView->checkAdaptImageBtn();
    emit m_ImageView->clicked();
    m_ImageView->mapToImage(QPoint());
    m_ImageView->mapToImage(QRect());
    m_ImageView->centerOn(5,5);
    m_ImageView->setRenderer();
    m_ImageView->setScaleValue(qreal());
}
TEST_F(gtestview, m_ScanPathsItem)
{
    VolumeMonitor::instance();
    ScanPathsItem* m_ScanPathsItem=new ScanPathsItem(m_JPGPath);
    m_ScanPathsItem->show();
}
TEST_F(gtestview, dapp)
{
    dApp->getRwLock();
    dApp->loadInterface(m_JPGPath);
    //    dApp->loadPixThread(QStringList(m_JPGPath));

    dApp->signalM->emit sendPathlist(list,m_JPGPath);
    dApp->wpSetter;
    dApp->viewerTheme;
    dApp->setter;
    DBManager::instance()->insertIntoAlbum(m_JPGPath,list);
    DBManager::instance()->getAllPaths();
    DBManager::instance()->getInfosByTimeline(m_JPGPath);
    DBManager::instance()->getInfoByPath(m_JPGPath);

    Importer::instance()->isRunning();
    Importer::instance()->appendDir(m_JPGPath,m_JPGPath);
    Importer::instance()->appendFiles(list,m_JPGPath);
    //        Importer::instance()->showImportDialog(m_JPGPath);
}
TEST_F(gtestview, BlurFrame)
{
    m_printOptionspage=new PrintOptionsPage();
    m_printOptionspage->show();
    m_blurFrame=new BlurFrame(m_printOptionspage);
    m_blurFrame->moveWithAnimation( 1200, 1000);

    m_blurFrame->getBorderColor() ;
    m_blurFrame->getBorderRadius() ;
    m_blurFrame->getBorderWidth() ;
    m_blurFrame->show();
    m_blurFrame->setBorderColor(QColor(200,155,200));
    m_blurFrame->resize(600,500);
    m_blurFrame->setBorderRadius(100);
    m_blurFrame->setBorderWidth(50);
    m_blurFrame->setCoverBrush(QBrush());
    m_blurFrame->setPos(QPoint(200,500));
    m_blurFrame->setMoveEnable(true);

    QTest::mousePress(m_blurFrame, Qt::LeftButton);
    QTest::mouseRelease(m_blurFrame, Qt::LeftButton);
    QTest::mouseClick(m_blurFrame, Qt::LeftButton);
    QTest::mouseMove(m_blurFrame, QPoint(50,50));
    QTest::keyClick(m_blurFrame, Qt::Key_Escape, Qt::ShiftModifier, 1000);
    QTest::mouseDClick(m_blurFrame,Qt::LeftButton);
}
TEST_F(gtestview, unionimage)
{
    //unionimage
    //        UnionImage_NameSpace::noneQImage();
    QString pppath=m_PNGPath;
    supportStaticFormat();
    supportMovieFormat();
    isSupportReading(pppath);
    QImage rimg(pppath);
    creatNewImage(rimg,800,600,0);
    QImage img2;
    QString errorMsg;
    loadStaticImageFromFile(m_DDSPath,img2,errorMsg);
    detectImageFormat(m_DDSPath);
    isNoneQImage(img2);
    rotateImage(90,img2);
    QString ddsPath=m_DDSPath;
    QString svgPath=m_SVGPath;
    rotateImageFIle(90,m_SVGPath,errorMsg);
    rotateImageFIle(90,pppath,errorMsg);
    rotateImageFIleWithImage(90,rimg,"1.jpg",errorMsg);
    rotateImageFIleWithImage(90,rimg,"1.svg",errorMsg);
    DetectImageFormat(m_SVGPath);
}
TEST_F(gtestview, imageutil)
{
    //        m_scrollBar=new ScrollBar();
    //        m_scrollBar->show();
    qDebug()<<"imageutil1";
    showInFileManager("");
    //    showInFileManager(m_JPGPath);
    qDebug()<<"imageutil22";
    copyImageToClipboard(list);
    trashFile(m_JPGPath);

    SpliteText("/usr/share/wallpapers/deepin/Hummingbird_by_Shu_Le.jpg/usr/share/wallpapers/deepin/Hummingbird_by_Shu_Le.jpg/usr/share/wallpapers/deepin/Hummingbird_by_Shu_Le.jpg",QFont(),20,false);
    SpliteText("/usr/share/wallpapers/deepin/Hummingbird_by_Shu_Le.jpg/usr/share/wallpapers/deepin/Hummingbird_by_Shu_Le.jpg/usr/share/wallpapers/deepin/Hummingbird_by_Shu_Le.jpg",QFont(),20,true);

    qDebug()<<"imageutil2";
    QString ppath=m_JPGPath;
    onMountDevice(ppath);
    mountDeviceExist(ppath);

    qDebug()<<"imageutil3";
    //utils::image
    QString pppath=m_JPGPath;
    imageSupportWrite(pppath);
    rotate(pppath,90);
    cutSquareImage(QPixmap(pppath),QSize(50,50));
    utils::image::getOrientation(pppath);
    bool iRet=false;
    //        utils::image::loadTga(pppath,iRet);

    qDebug()<<"imageutil4";
    getRotatedImage(pppath);
    cachePixmap(pppath);
    getThumbnail(pppath,iRet);
    supportedImageFormats();
    imageSupportWallPaper(pppath);
    utils::image::suffixisImage(pppath);

    wrapStr(m_JPGPath,QFont(),20);
    qDebug()<<"imageutil23";
}

TEST_F(gtestview, ExtensionPanel)
{
    m_extensionPanel=new ExtensionPanel(nullptr);
    m_extensionPanel->show();
    m_extensionPanel->setContent(new QWidget());
    m_extensionPanel->setContent(nullptr);

    QTest::mousePress(m_extensionPanel, Qt::LeftButton);
    QTest::mouseRelease(m_extensionPanel, Qt::LeftButton);
    QTest::mouseClick(m_extensionPanel, Qt::LeftButton);
    QTest::mouseMove(m_extensionPanel, QPoint(150,50));
    //        QTest::keyClick(m_extensionPanel, Qt::Key_Escape, Qt::ShiftModifier, 200);
    QTest::mouseDClick(m_extensionPanel,Qt::LeftButton);
    m_extensionPanel->setContent(new QWidget());
    m_extensionPanel->setContent(nullptr);
    QTest::mousePress(m_extensionPanel, Qt::LeftButton);
    QTest::mouseRelease(m_extensionPanel, Qt::LeftButton);
    QTest::mouseClick(m_extensionPanel, Qt::LeftButton);
    QTest::mouseMove(m_extensionPanel, QPoint(50,50));
    //        QTest::keyClick(m_extensionPanel, Qt::Key_Escape, Qt::ShiftModifier, 200);
    QTest::mouseDClick(m_extensionPanel,Qt::LeftButton);
}
TEST_F(gtestview, initTest2)
{



}
//延时推出程序
TEST_F(gtestview, initTest1)
{
    ScanPathsDialog::instance()->addPath(m_PNGPath);

    QTimer::singleShot(10000,[=]{
        return exit(0);
    });
}
