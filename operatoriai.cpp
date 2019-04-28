#include "struktura.h"

bool operator > (const studentas &a, const studentas &b) { return a.getGalutinis() > b.getGalutinis(); }

bool operator >= (const studentas &a, const studentas &b) { return a.getGalutinis() >= b.getGalutinis(); }

bool operator < (const studentas &a, const studentas &b) { return a.getGalutinis() < b.getGalutinis(); }

bool operator <= (const studentas &a, const studentas &b) { return a.getGalutinis() <= b.getGalutinis(); }

bool operator == (const studentas &a, const studentas &b) { return a.getGalutinis() == b.getGalutinis(); }

bool operator != (const studentas &a, const studentas &b) { return a.getGalutinis() != b.getGalutinis(); }