#El trabajo fue realizado por Manuel Otárola Madrigal - C05740.
#El script se encarga de mostrar la fecha del presente día, e indicar cuantos días faltan para
#el mes que el usuario define en la variable de ambiente ENTRADA.

export ENTRADA='september'

#Cambiar de español a ingles el comando date
LC_TIME=es_ES.UTF-8

SEMANA=$(LC_TIME=es_ES.UTF-8 date +%'A')
DIA=$(date +%'d')
MES=$(LC_TIME=es_ES.UTF-8 date +%'m')
ANO=$(date +%'Y')

EPOCA=$(date --date="1 $ENTRADA 2024" +'%s')
HOY=$(date +'%s')
SEGUNDOS_RESTANTES=$(($EPOCA - $HOY))
DIAS_RESTANTES=$(($SEGUNDOS_RESTANTES / 86400))

echo "Hoy es $SEMANA, $DIA de $MES, del año $ANO. Faltan $DIAS_RESTANTES dias para el mes de $ENTRADA"
