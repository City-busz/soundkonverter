
#ifndef SOUNDKONVERTER_REPLAYGAIN_METAFLAC_H
#define SOUNDKONVERTER_REPLAYGAIN_METAFLAC_H

#include "../../core/replaygainplugin.h"

#include <QUrl>

class ConversionOptions;

class soundkonverter_replaygain_metaflac : public ReplayGainPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.soundkonverter.replaygainplugin.metaflac" FILE "soundkonverter_replaygain_metaflac.json")
    Q_INTERFACES(ReplayGainPlugin)

public:
    soundkonverter_replaygain_metaflac();
    ~soundkonverter_replaygain_metaflac();

    QString name();

    QList<ReplayGainPipe> codecTable();

    bool isConfigSupported( ActionType action, const QString& codecName );
    void showConfigDialog( ActionType action, const QString& codecName, QWidget *parent );
    bool hasInfo();
    void showInfo( QWidget *parent );

    unsigned int apply( const QList<QUrl>& fileList, ApplyMode mode = Add );
    float parseOutput( const QString& output );
};

#endif // _SOUNDKONVERTER_REPLAYGAIN_METAFLAC_H_
