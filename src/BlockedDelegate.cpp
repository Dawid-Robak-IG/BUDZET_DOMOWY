#include "../inc/BlockedDelegate.hpp"

QString BlockedDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
    if (value.toInt() == 1)
        return "Zablokowany";
    else
        return "Aktywny";
}
