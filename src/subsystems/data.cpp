//distance, speed, angle tilted
/*
2.56894 97 3.9707
2.70042 105 0.699166
1.85811 81.5 6.137
1.80449 85 1.97002
2.08813 90 2.63459
2.90384 100 3.02058
3.41996 107 5.99289
3.03349 105 5.14557
2.47724 94 5.81963
2.20664 89 4.00389 

1.66197 79 -6.65536
1.74442 75 -1.28305
1.58241 72.5 -3.16306
1.44994 73 1.43674
1.55674 73 5.46375
2.32231 88 4.59142
2.30702 88 5.39626
2.72658 96.5 5.86145
2.573 94.5 3.87211
2.0137 86.5 2.79023

1.67539 86 3.70071
1.77599 85 3.59396
1.67353 83.5 2.37405
1.73566 83.5 0.98044
1.75442 83.5 0.273466
1.62294 83.5 3.66921
3.29914 107 5.91142
2.91415 106.5 8.0061
2.76514 106 4.53195
2.36704 85 1.68921

1.92067 79 2.73648
2.10455 84 3.88147
2.18118 85 3.95751
2.36784 86.5 5.2008
2.43888 91.5 8.22943
2.44962 92 3.79224
1.6992 80 2.84056
1.80245 85 2.18131
2.3252 89.5 1.4668
2.20212 88 4.02813
  
1.73867 83 9.22294
1.51623 78 2.9961
1.47949 78 1.88001
1.81539 80 4.54432
1.63558 80 4.41311
2.11906 85 2.16824
2.59863 97 3.50837
2.48433 95.5 1.03424
2.58264 96 7.72333
2.86054 102.5 4.98381
*/
/*back up
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

dataDistance = [2.56894,2.70042 ,1.85811 ,1.80449 ,2.08813 ,2.90384 ,3.41996 ,3.03349 ,2.47724 ,2.20664,
1.66197 ,1.74442 ,1.58241 ,1.44994,1.55674,2.32231,2.30702,2.72658 ,2.573 ,2.0137
,1.67539,1.77599,1.67353,1.73566,1.75442 ,1.62294,3.29914 ,2.91415,2.76514 ,2.36704,
1.92067,2.10455,2.18118,2.36784 ,2.43888 ,2.44962,1.6992,1.80245,2.3252 ,2.20212,
1.73867 ,1.51623,1.47949 ,1.81539 ,1.63558 ,2.11906 ,2.59863 ,2.48433 ,2.58264 ,2.86054 ]
dataDistance = np.array(dataDistance)

dataSpeed = [97,105 ,81.5,85,90,100,107,105,94,89,
79 ,75 ,72.5 ,73,73,88,88,96.5,94.5,86.5,
86 ,85 ,83.5 ,83.5 ,83.5,83.5 ,107 ,106.5,106 ,85, 
 79 , 84 , 85 , 86.5, 91.5 , 92 ,80 , 85 ,89.5, 88, 
 83 ,78,78 ,80 ,80 ,85 ,97 ,95.5 ,96 ,102.5 
]
dataSpeed = np.array(dataSpeed)

dataAngle = [3.9707,0.699166,6.137,1.97002,2.63459,3.02058,5.99289,5.14557,5.81963,4.00389,
-6.65536,-1.28305,-3.16306,1.43674,5.46375,4.59142,5.39626,5.86145,3.87211,2.79023,
3.70071,3.59396,2.37405,0.98044,0.273466,3.66921,5.91142,8.0061,4.53195,1.68921,
2.73648,3.88147,3.95751,5.2008,8.22943,3.79224,2.84056,2.18131,1.4668,4.02813,
9.22294,2.9961,1.88001,4.54432,4.41311,2.16824,3.50837,1.03424,7.72333,4.98381
]
dataAngle = np.array(dataAngle)

model_s =LinearRegression()
relation_square_s = 0
best_degree_s = 0
for i in range(1,51):
    poly = PolynomialFeatures(degree = i)
    dataDistance_poly = poly.fit_transform(dataDistance.reshape(-1,1))
    model_s.fit(dataDistance_poly, dataSpeed)
    dataSpeed_p = model_s.predict(dataDistance_poly)
    r_s = model_s.score(dataDistance_poly,dataSpeed)
    if r_s > relation_square_s:
        relation_square_s = r_s
        best_degree_s = i
print(relation_square_s, best_degree_s)
poly = PolynomialFeatures(degree = 4)#best_degree_s)
dataDistance_poly = poly.fit_transform(dataDistance.reshape(-1,1))
model_s.fit(dataDistance_poly, dataSpeed)
dataSpeed_p = model_s.predict(dataDistance_poly)
print(model_s.score(dataDistance_poly,dataSpeed))

plt.scatter(dataDistance,dataSpeed,marker='+')
plt.xlabel('distance between the robot and the goal(m)')
plt.ylabel('shooter speed')
plt.title('shooter speed based on the distance between the robot and the goal')
#line_fitter_speed = LinearRegression()
#line_fitter_speed.fit(dataDistance.reshape(-1,1), dataSpeed)
#plt.plot(dataDistance,line_fitter.predict(dataDistance.reshape(-1,1)))
plt.scatter(dataDistance,dataSpeed_p,marker='o')
plt.show()

model_a =LinearRegression()
relation_square_a = 0
best_degree_a = 0
for i in range(1,51):
    poly = PolynomialFeatures(degree = i)
    dataDistance_poly = poly.fit_transform(dataDistance.reshape(-1,1))
    model_a.fit(dataDistance_poly, dataAngle)
    dataAngle_p = model_a.predict(dataDistance_poly)
    r_a = model_a.score(dataDistance_poly,dataAngle)
    if r_a > relation_square_a:
        relation_square_a = r_a
        best_degree_a = i
print(relation_square_a, best_degree_a)
poly = PolynomialFeatures(degree = 3)#best_degree_a)
dataDistance_poly = poly.fit_transform(dataDistance.reshape(-1,1))
model_a.fit(dataDistance_poly, dataAngle)
dataAngle_p = model_a.predict(dataDistance_poly)
print(model_a.score(dataDistance_poly,dataSpeed))
plt.scatter(dataDistance,dataAngle,marker='+')
plt.xlabel('distance between the robot and the goal(m)')
plt.ylabel('angle of robot tilted towards goal')
plt.title('angle of robot tilted towards goal based on the distance between the robot and the goal')
plt.scatter(dataDistance,dataAngle_p,marker='o')
plt.show()
*/