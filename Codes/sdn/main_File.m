%correct results
% fileName = 'Sanet.graphml';
% fileName = 'Grnet.graphml';
% fileName = 'Sanet.graphml';
% fileName = 'Surfnet.graphml';

%load imbalanced results
% fileName = 'Geant2012.graphml';
% fileName = 'Agis.graphml';
 %fileName = 'Iris.graphml';
% fileName = 'Sprint.graphml';
fileName = 'Nsfnet.graphml';
inputfile = fopen(fileName);
[topology,latlong,nodenames,mat,P]= importGraphML(fileName); %--Read GML file to find nodes and adjacency matrix-
s = size (mat);
n = s (1,2);
 %testFunction (mat, n, 3);

% =========================================================================


avgCaseLatency(mat, n, 2);