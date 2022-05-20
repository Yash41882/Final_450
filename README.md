# Final_450
Codes of final 450 Sheet



import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression 
from sklearn.metrics import mean_squared_error

Experience = np.array([2.4,5.0,1.5,3.8,8.7,3.6,1.2,8.1,2.5,5,1.6,1.6,2.4,3.9,5.4])
Salary = np.array([2.1,4.7,1.7,3.6,8.7,3.2,1.0,8.0,2.4,6,1.1,1.3,2.4,3.9,4.8])


# CALCULATING USING MODEL

plt.scatter(Experience,Salary, color = 'red')
plt.xlabel("Experience")
plt.ylabel("Salary")
plt.show()


Experience = Experience.reshape(-1,1)
model = LinearRegression()
model.fit(Experience, Salary)
salary_pred= model.predict(Experience)
mse = mean_squared_error(Salary,salary_pred)
print('slope',model.coef_)
print('Intercept', model.intercept_)
print("MSE", mse)


# CALCULATING MANUALLY

n = np.size(Experience)
Emean = sum(Experience) / n
Smean = sum(Salary) / n
numerator = 0
denominator = 0
lst = []

for i in range(n):
    numerator += ((Experience[i] - Emean) * (Salary[i] - Smean))
    denominator += ((Experience[i] - Emean) * (Experience[i] - Emean))

    slope = (numerator / denominator)
    

Intercept = Smean - (slope * Emean)


summation = 0
for i in range(n):
    num = (Salary[i] - (Intercept + (slope * Experience[i]))) * (Salary[i] - (Intercept + (slope * Experience[i])))
    summation += num

MSE = summation / n

print("Slope ", slope)
print("Intercept ",Intercept)
print("MSE ", MSE)


















import numpy as np
import pandas as pd
import statsmodels.api as sm
import matplotlib.pyplot as plt
import seaborn as sns
sns.set()
from sklearn.cluster import KMeans

data = pd.read_csv('Countryclusters.csv')
data

plt.scatter(data['Longitude'],data['Latitude'])
plt.xlim(-180,180)
plt.ylim(-90,90)
plt.show()

x = data.iloc[:,1:3] # 1t for rows and second for columns
x


kmeans = KMeans(3)
means.fit(x)

identified_clusters = kmeans.fit_predict(x)
identified_clusters

array([1, 1, 0, 0, 0, 2])

data_with_clusters = data.copy()
data_with_clusters['Clusters'] = identified_clusters 
plt.scatter(data_with_clusters['Longitude'],data_with_clusters['Latitude'],c=data_with_clusters['Clusters'],cmap='rainbow')


wcss=[]
for i in range(1,7):
kmeans = KMeans(i)
kmeans.fit(x)
wcss_iter = kmeans.inertia_
wcss.append(wcss_iter)

number_clusters = range(1,7)
plt.plot(number_clusters,wcss)
plt.title('The Elbow title')
plt.xlabel('Number of clusters')
plt.ylabel('WCSS')
