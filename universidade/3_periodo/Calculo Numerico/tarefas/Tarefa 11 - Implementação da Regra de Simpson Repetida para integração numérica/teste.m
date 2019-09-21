area1 = simpsonR2058979(@(x) x.*log(x), 1, 2, 4)

area1 - 0.63631 < 0.000


area2 = simpsonR2058979(@(x) x.^3.*exp(x), -2, 2, 4)

area2 - 22.477 < 0.000

area3 = simpsonR2058979(@(x) 2./(x.^2+4), 0, 2, 6)

area3 - 0.78540 < 0.000


area4 = simpsonR2058979(@(x) exp(2*x).*sin(3*x), 0, 2, 8)

area4 - -14.183 < 0.000


area5 = simpsonR2058979(@(x) 1./sqrt(x.^2-4), 3, 5, 8)

area5 - 0.60439 < 0.000


area6 = simpsonR2058979(@(x)1./(x.*log(x)), e, e+2, 8)

area6 - 0.43920 < 0.000

area7 = simpsonR2058979(@(x)tan(x), 0, 3*pi/8, 8)

area7 - 0.96106 < 0.000

area8 = simpsonR2058979(@(x)tan(x), 0, 3*pi/8, 9)

area8 - -1