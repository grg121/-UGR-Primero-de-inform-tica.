nombre <- c("Juan","Salvador","Luis","José","Lola","Daniel","David","Carlos","Agustín","Maite")
nombre
nombre[4]
edad <- c(20,21,20,19,19,18,20,18,19,19)
sexo <- c(H,H,H,H,M,H,H,H,H,M)
media <- c(6.3,9.1,5.2,3.1,5.8,8.6,2.2,6.3,9.3,9.5)
data <- data.frame(nombre,edad,sexo,media)
H <- "H" 
M <- "M" 
data
save("data",file="./data.RData")
names(data)
data$altura <- c(1.75,1.80,1.77,1.75,1.71,1.64,1.69,1.95,1.75,1.67)
data
names(data)
editDataset(data)
library(relimp, pos=14)
altos <- subset(data, subset=altura>1.70)
altos
row.names(altos) <- as.character(altos$nombre)
altos$nombre <- NULL
altos
data <- within(data, {
  ESTADO <- Recode(media, '5:10 = "APROBADO"; 0:4.99 = "SUSPENSO"', as.factor.result=TRUE)
})
data
data$altura_cm <- with(data, altura*100)
data
data$ObsNumber <- 1:10
data
data$grupo <- with(data, bin.var(edad, bins=2, method='intervals', labels=c('grupo A','grupo B')))
data

