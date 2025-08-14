class MTuring:
    def __init__(self):
        self.chu = ["0", "1"]
        self.bd = ">"
        self.kt = "."

    def kiemtra(self, inp):
        if not (inp.startswith(self.bd) and inp.endswith(self.kt)):
            return False

        for kytu in inp[1:-1]:
            if kytu not in self.chu:
                return False

        return True


class M1(MTuring):
    def chay(self, inp):
        bang = list(inp)
        vitri = 0
        tt = "s"

        while tt != "h":
            kytu = bang[vitri]
            lenh = self.laylenh(tt, kytu)

            kytu_moi = lenh["viet"]
            huong = lenh["di"]
            tt_moi = lenh["tt"]

            bang[vitri] = kytu_moi

            if huong == "+":
                vitri += 1
            elif huong == "-":
                vitri -= 1

            tt = tt_moi

        return "".join(bang)

    def laylenh(self, tt, kytu):
        lenh = {
            ("s", "0"): {"viet": "1", "di": "+", "tt": "h"},
            ("s", "1"): {"viet": "0", "di": "+", "tt": "s"},
            ("s", ">"): {"viet": ">", "di": "+", "tt": "s"},
            ("s", "."): {"viet": ".", "di": "-", "tt": "h"},
        }
        return lenh[(tt, kytu)]

    def __call__(self, inp):
        if not self.kiemtra(inp):
            raise ValueError("Loi")
        return self.chay(inp)


class M2(MTuring):
    def chay(self, inp):
        bang = list(inp)
        vitri = len(bang) - 2
        tt = "s"

        while tt != "h":
            kytu = bang[vitri]
            lenh = self.laylenh(tt, kytu)

            kytu_moi = lenh["viet"]
            huong = lenh["di"]
            tt_moi = lenh["tt"]

            bang[vitri] = kytu_moi

            if huong == "+":
                vitri += 1
            elif huong == "-":
                vitri -= 1

            tt = tt_moi

        return "".join(bang)

    def laylenh(self, tt, kytu):
        lenh = {
            ("s", "0"): {"viet": "1", "di": "-", "tt": "s"},
            ("s", "1"): {"viet": "0", "di": "+", "tt": "h"},
            ("s", ">"): {"viet": ">", "di": "+", "tt": "s"},
            ("s", "."): {"viet": ".", "di": "-", "tt": "s"},
        }
        return lenh[(tt, kytu)]

    def __call__(self, inp):
        if not self.kiemtra(inp):
            raise ValueError("Loi")
        return self.chay(inp)


class M3(MTuring):
    def chay(self, inp):
        bang = list(inp)
        vitri = 0
        tt = "s"

        while tt != "h":
            kytu = bang[vitri]
            lenh = self.laylenh(tt, kytu)

            kytu_moi = lenh["viet"]
            huong = lenh["di"]
            tt_moi = lenh["tt"]

            bang[vitri] = kytu_moi

            if huong == "+":
                vitri += 1
            elif huong == "-":
                vitri -= 1

            tt = tt_moi

        return "".join(bang)

    def laylenh(self, tt, kytu):
        lenh = {
            ("s", "0"): {"viet": "1", "di": "+", "tt": "s"},
            ("s", "1"): {"viet": "0", "di": "+", "tt": "s"},
            ("s", ">"): {"viet": ">", "di": "+", "tt": "s"},
            ("s", "."): {"viet": ".", "di": "-", "tt": "h"},
        }
        return lenh[(tt, kytu)]

    def __call__(self, inp):
        if not self.kiemtra(inp):
            raise ValueError("Loi")
        return self.chay(inp)


class M4(MTuring):
    def chay(self, inp):
        kq = self.bd
        tt = "s"
        for kytu in inp[1:-1]:
            lenh = self.laylenh(tt, kytu)
            kytu_moi = lenh["viet"]
            tt_moi = lenh["tt"]

            if kytu_moi:
                kq += kytu_moi

            tt = tt_moi

        kq += self.kt
        return kq

    def laylenh(self, tt, kytu):
        lenh = {
            ("s", "0"): {"viet": "", "di": "+", "tt": "s"},
            ("s", "1"): {"viet": "1", "di": "+", "tt": "c"},
            ("s", ">"): {"viet": ">", "di": "+", "tt": "s"},
            ("s", "."): {"viet": ".", "di": "-", "tt": "h"},
            ("c", "0"): {"viet": "", "di": "+", "tt": "s"},
            ("c", "1"): {"viet": "1", "di": "+", "tt": "c"},
            ("c", "."): {"viet": ".", "di": "-", "tt": "h"},
        }
        return lenh[(tt, kytu)]

    def __call__(self, inp):
        if not self.kiemtra(inp):
            raise ValueError("Loi")
        return self.chay(inp)


class M5(MTuring):
    def __call__(self, inp):
        if not self.kiemtra(inp):
            raise ValueError("Loi")
        chuoi = inp[1:-1]
        return "co" if chuoi == chuoi[::-1] else "khong"


class M6(MTuring):
    def __call__(self, inp):
        if not self.kiemtra(inp):
            raise ValueError("Loi")
        return self.bd + "_" + inp[1:]


def test():
    test_cases = {
        "M1": [">1111.", ">1010.", ">0000."],
        "M2": [">1000.", ">1111.", ">0001."],
        "M3": [">01001.", ">11100.", ">00000."],
        "M4": [">01001.", ">10001.", ">00100."],
        "M5": [">010010.", ">01100.", ">1001."],
        "M6": [">1111.", ">0000.", ">1010."]
    }

    may = {
        "M1": M1(),
        "M2": M2(),
        "M3": M3(),
        "M4": M4(),
        "M5": M5(),
        "M6": M6()
    }

    for ten, m in may.items():
        print(f"\nTest {ten}:")
        print("-" * 40)

        for inp in test_cases[ten]:
                kq = m(inp)
                print(f"Input:  {inp}")
                print(f"Output: {kq}")
                print("-" * 20)
           


if __name__ == "__main__":
    test()