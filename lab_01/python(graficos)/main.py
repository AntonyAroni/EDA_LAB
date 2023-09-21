import matplotlib.pyplot as plt

frecuencias = {}

with open("datos_dimension_5000.txt", "r") as archivo:
    for linea in archivo:
        distancia = float(linea.strip())
        if distancia in frecuencias:
            frecuencias[distancia] += 1
        else:
            frecuencias[distancia] = 1

distancias = list(frecuencias.keys())
frecuencias = list(frecuencias.values())

plt.bar(distancias, frecuencias, width=0.1)
plt.xlabel("Distancia")
plt.ylabel("Frecuencia")
plt.title("Histograma de Distancia vs. Frecuencia")
plt.grid(True)


plt.savefig("histograma5000.png")

plt.show()
