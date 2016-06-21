#include "musicpp.h"

static Interval INTERVAL_TABLE[12][2] = {
  { Interval(IntervalQuality::PERFECT,    IntervalNumber::UNISON),
    Interval(IntervalQuality::DIMINISHED, IntervalNumber::SECOND)  },
  { Interval(IntervalQuality::MINOR,      IntervalNumber::SECOND),
    Interval(IntervalQuality::AUGMENTED,  IntervalNumber::UNISON)  },
  { Interval(IntervalQuality::MAJOR,      IntervalNumber::SECOND),
    Interval(IntervalQuality::DIMINISHED, IntervalNumber::THIRD)   },
  { Interval(IntervalQuality::MINOR,      IntervalNumber::THIRD),
    Interval(IntervalQuality::AUGMENTED,  IntervalNumber::SECOND)  },
  { Interval(IntervalQuality::MAJOR,      IntervalNumber::THIRD),
    Interval(IntervalQuality::DIMINISHED, IntervalNumber::FOURTH)  },
  { Interval(IntervalQuality::PERFECT,    IntervalNumber::FOURTH),
    Interval(IntervalQuality::AUGMENTED,  IntervalNumber::THIRD)   },
  { Interval(IntervalQuality::AUGMENTED,  IntervalNumber::FOURTH),
    Interval(IntervalQuality::DIMINISHED, IntervalNumber::FIFTH)   },
  { Interval(IntervalQuality::PERFECT,    IntervalNumber::FIFTH),
    Interval(IntervalQuality::DIMINISHED, IntervalNumber::SIXTH)   },
  { Interval(IntervalQuality::MINOR,      IntervalNumber::SIXTH),
    Interval(IntervalQuality::AUGMENTED,  IntervalNumber::FIFTH)   },
  { Interval(IntervalQuality::MAJOR,      IntervalNumber::SIXTH),
    Interval(IntervalQuality::DIMINISHED, IntervalNumber::SEVENTH) },
  { Interval(IntervalQuality::MINOR,      IntervalNumber::SEVENTH),
    Interval(IntervalQuality::AUGMENTED,  IntervalNumber::SIXTH)   },
  { Interval(IntervalQuality::MAJOR,      IntervalNumber::SEVENTH),
    Interval(IntervalQuality::DIMINISHED, IntervalNumber::UNISON)  }};

PitchClass NamedPitch::Class() const {
  return static_cast<PitchClass>((static_cast<int>(BASE_CLASS_PITCHES[static_cast<int>(p_)]) +
	 acc_count_ * static_cast<int>(acc_type_)) % NUM_PITCH_CLASSES);
}

Interval IntervalBetween(NamedPitch lower, NamedPitch upper) {
  IntervalNumber number = static_cast<IntervalNumber>(
    ((static_cast<int>(upper.Base()) - static_cast<int>(lower.Base())) % NUM_BASE_PITCHES) + 1);

  int delta =
    (static_cast<int>(upper.Class()) - static_cast<int>(lower.Class())) % NUM_PITCH_CLASSES;

  for (const Interval& candidate : INTERVAL_TABLE[delta]) {
    if (candidate.Number() == number) return candidate;
  }

  CHECK(false);
}

