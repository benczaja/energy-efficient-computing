from matplotlib import pyplot as plt
import numpy as np

data = np.loadtxt("results.txt").T

Size=data[0] 
Time=data[1] 
Joule=data[2]  
Watt=data[3] 


plt.scatter(Size,Time)
plt.xlabel("Matrix Size")
plt.ylabel("Execution Time (s)")
plt.ylim(0,np.max(Time))
plt.savefig("size_v_time.png",dpi=150)
plt.close()

plt.scatter(Size,Joule)
plt.xlabel("Matrix Size")
plt.ylabel("Energy (J)")
plt.ylim(0,np.max(Joule))
plt.savefig("size_v_joule.png",dpi=150)
plt.close()

plt.scatter(Size,Watt)
plt.xlabel("Matrix Size")
plt.ylabel("Power (W)")
plt.ylim(0,np.max(Watt))
plt.savefig("size_v_watt.png",dpi=150)
plt.close()

