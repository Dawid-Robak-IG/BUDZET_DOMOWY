#include "CyklicznyDelegate.hpp"

QString CyklicznyDelegate::displayText(const QVariant &value, const QLocale &) const
{
    if (value.toInt() == 1)
        return "Cykliczna";
    else
        return "Jednorazowa";
}
