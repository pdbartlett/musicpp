#include "musicpp.h"

int main(int argc, char** argv) {
  NamedPitch np1 = NamedPitch(BasePitch::C);
  CHECK(np1.Class() == PitchClass::C);

  NamedPitch np2 = NamedPitch(BasePitch::E, Accidental::FLAT);
  CHECK(np2.Class() == PitchClass::Eb);

  Interval i = IntervalBetween(np1, np2);
  CHECK(i.Number() == IntervalNumber::THIRD);
  CHECK(i.Quality() == IntervalQuality::MINOR);

  return static_cast<int>(np1.Class());
}
