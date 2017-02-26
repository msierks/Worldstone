#pragma once

#include <MpqArchive.h>
#include <QWidget>
#include <dc6.h>

using WorldStone::DC6;

class DC6View : public QWidget
{
    Q_OBJECT
public:
    DC6View(QWidget* parent = nullptr, Qt::WindowFlags flags = {});
public slots:
    /// @brief Loads the palette from give folder, replacing old ones
    /// @note For now, only load pal.dat
    void loadPalettes(const QString& palettesFolder);
    void displayDC6(const QString& fileName);
    void refreshDC6Frame();

private:
    Palette         palette;
    class QLabel*   headerInfo       = nullptr;
    class QLabel*   frameHeaderInfo  = nullptr;
    class QLabel*   frameInfo        = nullptr;
    /// Could be changed to QGraphicsView for debug stuff
    class QLabel*   image            = nullptr;
    class QSpinBox* frameSpinBox     = nullptr;
    class QSpinBox* directionSpinBox = nullptr;

    std::unique_ptr<DC6> currentDC6;
};