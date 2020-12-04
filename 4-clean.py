import sys
import re

def check(fields: dict[str, str]) -> bool:
    def guard(val: bool) -> None:
        if not val:
            raise ValueError

    try:
        guard(1920 <= int(fields["byr"]) <= 2002)
        guard(2010 <= int(fields["iyr"]) <= 2020)
        guard(2020 <= int(fields["eyr"]) <= 2030)
        h = fields["hgt"]
        guard(
            (h.endswith("cm") and 150 <= int(h[:-2]) <= 193) or
            (h.endswith("in") and 59 <= int(h[:-2]) <= 76)
        )
        guard(re.match("^#[a-f0-9]{6}$", fields["hcl"]))
        guard(fields["ecl"] in {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"})
        guard(re.match("^[0-9]{9}$", fields["pid"]))
    except (KeyError, ValueError):
        return False
    return True

def main():
    res = 0
    for part in sys.stdin.read().split("\n\n"):
        fields = {}
        for word in part.split():
            key, value = word.split(":", 1)
            fields[key] = value
        if check(fields):
            res += 1

    print(res)

if __name__ == "__main__":
    main()
