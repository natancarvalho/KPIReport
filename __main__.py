# Run this app with `python app.py` and
# visit http://127.0.0.1:8050/ in your web browser.
import time
import os
import signal
import sys
import dash
from dash import Dash, html, dcc, Input, Output, dash_table, DiskcacheManager, CeleryManager
import pandas as pd
import plotly.express as px


external_stylesheets = ['https://codepen.io/chriddyp/pen/bWLwgP.css']

app = Dash(__name__, external_stylesheets=external_stylesheets)

df5 = pd.read_csv('/home/natan/OptimumG/Dev/KPIReport/csv/dados.csv')

app.layout = html.Div([
    html.H4('01 - KPI - Lap Time[s]'),
    dcc.Store(id="shutdown-permission"),
    html.Div([html.P(id="paragraph_id", children=["Button not clicked"])]),
    html.Button(id="button_id", children="Run Job!"),
    dcc.Graph(id='kpi-lap-times'),
    dcc.RangeSlider(
        id='range-slider',
        min=119000, max=122000, step=500,
        value=[0, 122000]
    ),
    dash_table.DataTable(
        data=df5.to_dict('records'),
        columns=[{'id': c, 'name': c} for c in df5.columns],
        page_size=10
    ),
])

@app.callback(
    Output("kpi-lap-times", "figure"),
    Input("range-slider", "value"))


def update_chart(slider_range):
    df = pd.read_csv('/home/natan/OptimumG/Dev/KPIReport/OutingsCSV/Outing1.csv')
    df2 = pd.read_csv('/home/natan/OptimumG/Dev/KPIReport/OutingsCSV/Outing2.csv')
    df3 = pd.read_csv('/home/natan/OptimumG/Dev/KPIReport/OutingsCSV/Outing3.csv')
    df4 = pd.read_csv('/home/natan/OptimumG/Dev/KPIReport/OutingsCSV/Outing4.csv')
    df = df.append(df2, ignore_index=True)
    df = df.append(df3, ignore_index=True)
    df = df.append(df4, ignore_index=True)

    low, high = slider_range
    mask = (df['LapTime'] > low) & (df['LapTime'] < high)
    fig = px.line(df[mask], x='TotalLapNumber', y='LapTime', color='OutingNumber', title='01 - KPI - Lap Time[s]',
                  markers=True)

    return fig


@dash.callback(
    output=Output("paragraph_id", "children"),
    inputs=Input("button_id", "n_clicks"),
)
def update_clicks(n_clicks):
    time.sleep(2.0)
    return os.kill(os.getpid(), signal.SIGTERM)

# def generate_table(dataframe, max_rows=10):
#     return html.Table([
#         html.Thead(
#             html.Tr([html.Th(col) for col in dataframe.columns])
#         ),
#         html.Tbody([
#             html.Tr([
#                 html.Td(dataframe.iloc[i][col]) for col in dataframe.columns
#             ]) for i in range(min(len(dataframe), max_rows))
#         ])
#     ])
#
#
# app.layout = html.Div([
#     html.H4(children='US Agriculture Exports (2011)'),
#     generate_table(df)
# ])


if __name__ == '__main__':
    app.run_server(debug=True)
