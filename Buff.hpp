class Buff {
public:
    enum class Type {
        Anger,
        Armor,
    };

    Buff(Type type, int magnitude, int duration)
        : type(type), magnitude(magnitude), duration(duration) {}

    Type type;
    int magnitude; // L'intensité du buff
    int duration;  // Durée en unités de temps ou ticks
};
