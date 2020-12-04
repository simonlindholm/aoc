import sys
import re

def check_year(s, f, t):
    v = int(s)
    assert f <= v <= t

def check_regex(s, r):
    assert re.match(r, s)

def check(fields):
    try:
        check_year(fields["byr"], 1920, 2002)
        check_year(fields["iyr"], 2010, 2020)
        check_year(fields["eyr"], 2020, 2030)
        h = fields["hgt"]
        val = int(h[:-2])
        if h.endswith("cm"):
            if not (150 <= val <= 193):
                return False
        elif h.endswith("in"):
            if not (59 <= val <= 76):
                return False
        else:
            return False
        check_regex(fields["hcl"], "^#[a-f0-9]{6}$")
        if fields["ecl"] not in ("amb", "blu", "brn", "gry", "grn", "hzl", "oth"):
            return False
        check_regex(fields["pid"], "^[0-9]{9}$")
    except (AssertionError, KeyError, ValueError):
        return False
    return True

res = 0
for part in sys.stdin.read().split("\n\n"):
    fields = {}
    for word in part.split():
        key, value = word.split(":", 1)
        fields[key] = value
    if check(fields):
        res += 1

print(res)
