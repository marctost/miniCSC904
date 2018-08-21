
#ifndef plotting_functions_h
#define plotting_functions_h

#include "root_tools.h"
#include "rate_labeling.h"

TGraph* make_graph_strip(int i, vector<PlotterLines> run, int acc_charge[], int number_of_points){
    
    TGraph *graph = new TGraph(number_of_points);
    
    // Creating the TGraph and filling it with 5 points (number of runs)
    // The first number is the "point number" and will always be 0-4. the second number is x-axis, which is the accumulated charge, and has to be entered by hand. The last number is charge mean, where the at(i) refers to which wire pair is currently being looked at
    
    for (int j=0; j<number_of_points; j++){
        graph->SetPoint(j, acc_charge[j], run[j].lines[1].at(i));
    }
    return graph;
}

// Sets the marker style and coloring for each graph
TGraph* format_me_strip(TGraph* graph, Color_t color){
    graph->SetLineColor(color);
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(0.8);
    graph->SetMarkerColor(color);
    graph->SetLineWidth(2.0);
    
    return graph;
}




TGraph* make_graph_cluster(string norm_or_no, int i, vector<PlotterLines> run){
    
    TGraph *graph = new TGraph(6);
    
    // Note the the first number is the "point number" and will always be 0-4, the second number the accumlated charge, and the last number is charge mean
    
    if (norm_or_no=="ref"){
        graph->SetPoint(0, 0, run[0].lines[0].at(i)/run[0].lines[0].at(11));
        graph->SetPoint(1, 53, run[1].lines[0].at(i)/run[1].lines[0].at(11));
        graph->SetPoint(2, 95, run[2].lines[0].at(i)/run[2].lines[0].at(11));
        graph->SetPoint(3, 121, run[3].lines[0].at(i)/run[3].lines[0].at(11));
        graph->SetPoint(4, 149, run[4].lines[0].at(i)/run[4].lines[0].at(11));
        graph->SetPoint(5, 180, run[5].lines[0].at(i)/run[5].lines[0].at(11));
        //graph->SetPoint(6, 200, run[6].lines[0].at(i)/run[6].lines[0].at(11));
        //graph->SetPoint(7, 205, run[7].lines[0].at(i)/run[7].lines[0].at(11));
        //graph->SetPoint(8, 210, run[8].lines[0].at(i)/run[8].lines[0].at(11));
        //graph->SetPoint(9, 215, run[9].lines[0].at(i)/run[9].lines[0].at(11));
        //graph->SetPoint(10, 220, run[10].lines[0].at(i)/run[10].lines[0].at(11));
    }
    else if (norm_or_no=="irr"){
        graph->SetPoint(0, 0, run[0].lines[0].at(i)/run[0].lines[0].at(5));
        graph->SetPoint(1, 53, run[1].lines[0].at(i)/run[1].lines[0].at(5));
        graph->SetPoint(2, 95, run[2].lines[0].at(i)/run[2].lines[0].at(5));
        graph->SetPoint(3, 121, run[3].lines[0].at(i)/run[3].lines[0].at(5));
        graph->SetPoint(4, 149, run[4].lines[0].at(i)/run[4].lines[0].at(5));
        graph->SetPoint(5, 180, run[5].lines[0].at(i)/run[5].lines[0].at(5));
        //graph->SetPoint(6, 200, run[6].lines[0].at(i)/run[6].lines[0].at(5));
        //graph->SetPoint(7, 205, run[7].lines[0].at(i)/run[7].lines[0].at(5));
        //graph->SetPoint(8, 210, run[8].lines[0].at(i)/run[8].lines[0].at(5));
        //graph->SetPoint(9, 215, run[9].lines[0].at(i)/run[9].lines[0].at(5));
        //graph->SetPoint(10, 220, run[10].lines[0].at(i)/run[10].lines[0].at(5));
    }
    else{
        graph->SetPoint(0, 0, run[0].lines[0].at(i));
        graph->SetPoint(1, 53, run[1].lines[0].at(i));
        graph->SetPoint(2, 95, run[2].lines[0].at(i));
        graph->SetPoint(3, 121, run[3].lines[0].at(i));
        graph->SetPoint(4, 149, run[4].lines[0].at(i));
        graph->SetPoint(5, 180, run[5].lines[0].at(i));
        //graph->SetPoint(6, 200, run[6].lines[0].at(i));
        //graph->SetPoint(7, 205, run[7].lines[0].at(i));
        //graph->SetPoint(8, 210, run[8].lines[0].at(i));
        //graph->SetPoint(9, 215, run[9].lines[0].at(i));
        //graph->SetPoint(10, 220, run[10].lines[0].at(i));
    }
    return graph;
}

TGraph* format_me_cluster(TGraph* graph, Color_t color){
    graph->SetLineColor(color);
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(0.8);
    graph->SetMarkerColor(color);
    graph->SetLineWidth(2.0);
    
    return graph;
}



PlotterLines resize_DC(PlotterLines graph_line){
    for (int g=graph_line.lines[0].size()-1; g>0; g=g-1){
        if (graph_line.lines[0].at(g)==graph_line.lines[0].at(g-1)){
            graph_line.lines[0].pop_back();
            graph_line.lines[1].pop_back();
        }
        else{
            continue;
        }
    }
    return graph_line;
}

TGraph* make_graph_DC_HV(PlotterLines graph_line){
    TGraph *graph = new TGraph(graph_line.lines[0].size());
    for (int i=0; i<graph_line.lines[0].size(); i++){
        // The SetPoint function takes (i, x, y) as its arguments, so here it can be seen that side-by-side pairs in the excel document are put into each line.
        graph->SetPoint(i,graph_line.lines[0].at(i), graph_line.lines[1].at(i));
    }
    return graph;
}

TGraph* format_me_DC(TGraph* graph, Color_t color, float alpha){
    graph->SetLineColorAlpha(color, alpha);
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(0.8);
    graph->SetMarkerColorAlpha(color, alpha);
    graph->SetLineWidth(2.0);
    
    return graph;
}

TGraph* make_graph_DC(int i, vector<PlotterLines> run, int acc_charge[], int number_of_points){
    TGraph *graph = new TGraph();
    
    //first argument is point number
    //second number is the dose (x-axis)
    //last number is the current at 3.6kV
    //argument of "at" corresponds to the row within
    for (int j=0; j<number_of_points; j++){
        graph->SetPoint(j, acc_charge[j], run[j].lines[1].at(i));
    }
    return graph;
}



TGraph* format_graph_gg(TGraph* graph, Color_t color, float alpha){
    graph->SetLineColorAlpha(color, alpha);
    graph->SetMarkerSize(0.8);
    graph->SetMarkerStyle(20);
    graph->SetMarkerColorAlpha(color, alpha);
    graph->SetLineWidth(2.0);
    return graph;
}


TGraph* make_graph_gg(PlotterLines voltage, PlotterLines graph_line, Color_t color, float alpha){
    TGraph *graph = new TGraph(graph_line.lines[0].size());
    for (int i=0; i<graph_line.lines[0].size(); i++){
        graph->SetPoint(i,voltage.lines[0].at(i), graph_line.lines[0].at(i));
    }
    TGraph* graph_fin = format_graph_gg(graph, color, alpha);
    return graph_fin;
}



TCanvas* rate_plotting(PlotterLines graphLines, PlotterLines subtraction, string subtract_or_no, string irr_or_ref, int line_num, Color_t colors_used[], float color_trans[], TString acc_charges[], TString title){
    
    TCanvas *canvas = make_canvas();
    TLegend *legend = make_legend();
    canvas->cd();
    
    int number_of_points = graphLines.size;
    
    if (subtract_or_no=="subtract"){
        for (int q=0; q<line_num; q++){
            for (int w=0; w<number_of_points; w++){
                subtraction.lines[q].at(w)=0;
            }
        }
    }
    
    for (int j=0; j<line_num; j++){
        //Create the graph by looping over the number of points
        TGraph *graph = new TGraph(number_of_points);
        for (int i=0; i<number_of_points; i++){
            //if (j==)
            if (graphLines.lines[j].at(i)<0){
                // Note that we are using the .voltages here, this is specific to the rate plots, and it automatically picks the "0" column, where the voltages are located.
                graph->SetPoint(i, graphLines.voltages.at(i),0);
            }
            else{
                graph->SetPoint(i,graphLines.voltages.at(i),graphLines.lines[j].at(i)+ subtraction.lines[j].at(i));
            }
        }
        
        Color_t color = colors_used[2];
        float transparency = color_trans[j];
        if (irr_or_ref=="irr_irr"){
            color = colors_used[0];
        }
        if (j==line_num-1){
            color = colors_used[3];
            transparency=1;
            if (irr_or_ref=="irr_irr"){
                color = colors_used[1];
            }
        }
        
        // Some maintanence and labeling for the plot.
        graph->GetXaxis()->SetTitle("Voltage (kV)");
        graph->GetYaxis()->SetTitle("Hertz");
        graph->SetLineColorAlpha(color, transparency);
        graph->SetLineWidth(2.0);
        
        // Use the function to great the legend entries one by one
        TString lengend_title = get_leg(j, acc_charges[j]);
        legend->AddEntry(graph, lengend_title);
        
        //Manually set the dimensions of the plot to keep it consistent for all rate plots
        graph->SetMaximum(500);
        graph->GetXaxis()->SetRangeUser(2,4);
        
        //Some line styling.
        graph->SetMarkerStyle(20);
        graph->SetMarkerSize(0.8);
        graph->SetMarkerColorAlpha(color, transparency);
        
        // Draw the plots
        if (j==0){
            graph->SetTitle(title);
            graph->Draw();
        }
        else{
            graph->Draw("SAME P L");
        }
    }
    legend->Draw("SAME");

    return canvas;
}


#endif /* plotting_functions_h */
