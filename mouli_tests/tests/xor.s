.name "xor"
.comment "lol"

before:
middle:
xor %-2147483648, %-2147483648, r1
xor %2147483648, %-2147483648, r1
xor %2147483647, %-2147483648, r1
xor %214748364732488, %-2147483648, r1
xor %1, %-2147483648, r1
xor %-1, %-2147483648, r1
xor %10, %-2147483648, r1
xor %-10, %-2147483648, r1
xor %-500, %-2147483648, r1
xor %500, %-2147483648, r1
xor %:before, %-2147483648, r1
xor %:middle, %-2147483648, r1
xor %:after, %-2147483648, r1
after: