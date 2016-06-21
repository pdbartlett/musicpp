#ifndef __MUSICPP_MUSICPP_H__
#define __MUSICPP_MUSICPP_H__

#include <cstddef>
#include <cstdlib>

#define CHECK(condition) if (!(condition)) exit(1)

enum class BasePitch { C, D, E, F, G, A, B };
enum class PitchClass { C, Db, D, Eb, E, F, Gb, G, Ab, A, Bb, B };

constexpr size_t NUM_BASE_PITCHES = 7;
constexpr size_t NUM_PITCH_CLASSES = 12;
constexpr PitchClass BASE_CLASS_PITCHES[] = {
    PitchClass::C, PitchClass::D, PitchClass::E, PitchClass::F,
    PitchClass::G, PitchClass::A, PitchClass::B
};

enum class Accidental { FLAT = -1, NATURAL, SHARP };

class NamedPitch final {
 public:
  NamedPitch(BasePitch p, Accidental acc_type, std::size_t acc_count)
      : p_(p), acc_type_(acc_type), acc_count_(acc_count) {}
  NamedPitch(BasePitch p, Accidental acc) : NamedPitch(p, acc, 1) {}
  NamedPitch(BasePitch p) : NamedPitch(p, Accidental::NATURAL, 0) {}

  BasePitch Base() const { return p_; }

  PitchClass Class() const;

 private:
  BasePitch p_;
  Accidental acc_type_;
  std::size_t acc_count_;
};

enum class IntervalNumber { UNISON = 1, SECOND, THIRD, FOURTH, FIFTH, SIXTH, SEVENTH };
enum class IntervalQuality { DIMINISHED = -2, MINOR, PERFECT, MAJOR, AUGMENTED };

class Interval final {
 public:
  Interval(IntervalQuality quality, IntervalNumber number) : number_(number), quality_(quality) {}

  IntervalNumber Number() const { return number_; }
  IntervalQuality Quality() const { return quality_; }

 private:
  IntervalNumber number_;
  IntervalQuality quality_;
};

Interval IntervalBetween(NamedPitch lower, NamedPitch upper);

#endif // __MUSICPP_MUSICPP_H__
