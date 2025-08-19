#include <QApplication>
#include <QLabel>
#include <QStandardPaths>
#include <KLocalizedString>
#include <KAboutData>
#include "ktexteditor/ktexteditor/Editor"
#include <KLocalizedContext>
#include "Dialog1.h"
#include <QStyleFactory>

void fakeFunc()
{
	auto fake = KTextEditor::Editor::instance();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    KLocalizedString::setApplicationDomain("zzz");

    KLocalizedString::addDomainLocaleDir(QStringLiteral("zzz").toUtf8(), QStringLiteral("C:/ProgramData/locale"));

    auto paths = QStandardPaths::locateAll(QStandardPaths::GenericDataLocation, QStringLiteral("locale"), QStandardPaths::LocateDirectory);

    const QList<QLocale> allLocales = QLocale::matchingLocales(QLocale::AnyLanguage, QLocale::AnyScript, QLocale::AnyCountry);
    for (const QLocale& l : allLocales)
    {
        auto languageCode = l.name();
        if (languageCode == QStringLiteral("zh_CN"))
        {
            auto flag = KLocalizedString::isApplicationTranslatedInto(languageCode);
            int j{ 1 };
        }
    }

	auto langs = KLocalizedString::availableDomainTranslations(QStringLiteral("zzz").toUtf8());

    KAboutData aboutData(
        QStringLiteral("demo"),
        i18n("Demo"),
        QStringLiteral("1.0"),
        i18n("A simple KDE KI18n demo."),
        KAboutLicense::GPL,
        i18n("(C) 2024 Your Name")
    );
    KAboutData::setApplicationData(aboutData);

    /*QLabel label(i18n("Hello, KDE World!"));
    label.show();*/
	auto keys = QStyleFactory::keys();
	auto style = QStyleFactory::create(QStringLiteral("Breeze"));
    qApp->setStyle(style);
	Dialog1 dialog;
    dialog.show();

    return app.exec();
}
