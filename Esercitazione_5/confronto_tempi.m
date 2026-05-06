dati_tempi = load("tempi_matlab.txt");

N = dati_tempi(:, 1);
tempo_bubble=dati_tempi(:,2);
tempo_insertion=dati_tempi(:,3);
tempo_selection=dati_tempi(:,4);
tempo_std=dati_tempi(:,5);
tempo_merge=dati_tempi(:, 6);
tempo_quick=dati_tempi(:, 7);

figure;
loglog(N, tempo_bubble, "-o", "LineWidth", 2);
hold on;
loglog(N, tempo_insertion, "-o", "LineWidth", 2);
loglog(N, tempo_selection, "-o", "LineWidth", 2);
loglog(N, tempo_std, "-o", "LineWidth", 2);
loglog(N, tempo_merge, "-o", "LineWidth", 2);
loglog(N, tempo_quick, "-o", "LineWidth", 2);

xlabel("Dimensione del vettore");
ylabel("Tempo di esecuzione in secondi");
title("Confronto tempi tra algoritmi di ordinamento")

legend("Bubble Sort", "Insertion Sort", "Selection Sort","std::sort (Libreria)", "Merge Sort", "Quick Sort", "Location", "northeastoutside");