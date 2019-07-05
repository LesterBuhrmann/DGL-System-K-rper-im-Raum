# DGL-System-K-rper-im-Raum
Für vorzugsweise drei Massen oder Ladungsträger mit verschiedenen Anfangsgeschwindigkeiten werden deren Ortsvektoren numerisch berechnet.
In unserem Projekt losen wir mit dem Eulerverfahren das Differentialgleichungssystem, dass auf den Newtonschen Bewegungsgleichungen 
fur Massepunkte aufbaut.
Zunachst deklarieren wir eine Vektor 3-D Klasse(gennant Vektor) mit den dazugehorigen Rechenoperationen fur Vektoren.
Anschliessend werden Arrays vom Typ vector fur alle zeitlich variablen vektoriellen Grossen angelegt.
Die Anfangsorte/geschwindigkeiten werden gewahlt und in die Arrays eingeschoben.
Testweise lauft das mit den Massen von Merkur, Erde und Mars, die anfanglichen Geschwindigkeiten sind zufallig gewahlt.
In der For-Schleife werden bei jeder Iteration die aktuellen Abstandsvektoren aus den Ortsvekoren berechnet.
Aus diesem werden wiederum die Kraftvektoren nach dem Newtonschen Gravitationsgesetz berechnet, nach dem Prinzip 
der Tangentenzerlegung  werden die neuen Geschwindigkeitsvektoren berechnet. 
Die in der vorherigen Iteration berechneten Geschwindigkeitsvektoren dienen nun zur Approximation der nachsten Ortsvektoren
per Tangentenzerlegung.
Die Tangentenzerlegung funktioniert folgendermassen; y(x-x_0)=y(x_0)+y'(x_0)*(x-x_0)+r(x-x_0, x_0)
Dabei ist r der mit x-x_0 nichtlinear gegen 0 gehende Restterm. Daraus lasst sich herleiten, dass die Ungenauigkeit(Hohe des
Restterms) umso kleiner, je kleiner x-x_0 bei uns dt genannt, ist. Damit zu jeden Zeitpunkt ein ausreichend kleines dt gewahlt wird
ist dt vom Zeitschritt abhangig. Es wurde also ein vector array fur dt mit Werten dt[i] deklariert. Kommen sich die Korper zu nahe,
muss die Zeitschrittlange dt verkleinert werden und dies geschieht uber die angefugte If-Bedingung. 
Der if-else Befehl stellt insgesamt sicher, dass, wenn 2 der 3 Korper sich zu nahe kommen und die Krafte sowie Geschwindigkeiten
zu gross werden, die Zeitschrittlange vom kleinsten Abstand aller 3 Korper abhangig wird.
Sonst wurden die Korper in vielen Situationen einfach wegfliegen. 
Damit wird leider die Zeitdifferenz zwischen 2 Zeitschritten variabel. Wurden die Inhalte der arrays einfach so in
eine txt Datei geschrieben werden, wahre die Zeitachse nicht linear. Geschwindigkeiten konnten bei bewegten Plots der txt Dateien
nicht verhaltnismassig wiedergegeben werden. Dafur wird in einer weiteren For-Schleife der vector tn
mit den Nummern der Zeitpunkte im anfanglich deklarierten vector t, die genau um den grobsten Zeitschritt dt[O] entfernt sind, 
gefullt.
Beim Erstellen der Textdatei werden nur die Stellen in den vector arrays der auszugebenden Grossen in die Textdatei eingeschrieben,
die in tn eingespeichert sind, also gleichen Zeitabstand haben.
