import React, { useState } from 'react';
import axios from 'axios';

const App = () => {
  const [data, setData] = useState(null);
  const [lists, setList] = useState(null);
  const onClick = async () => {
    try {
      const res = await axios.get(
        //'https://newsapi.org/v2/top-headlines?country=kr&apiKey=1e1edc8170eec8cad4c927ae8876cd3f',
        //'http://api.openweathermap.org/data/2.5/weather?q=Seoul&units=metric&lang=kr&appid=1e1edc8170eec8cad4c927ae8876cd3f',
        'http://api.openweathermap.org/data/2.5/forecast?q=Busan,kr&units=metric&lang=kr&appid=1e1edc8170eec8cad4c927ae8876cd3f',
      );
      setData(res.data);
      setList(res.data.list);
    } catch(e) {
      console.log(e);
    }
  };

  const { city : {name: 도시, country: 국가} } = data || { city:{}};
  const r =  {도시, 국가};

  const r2 = !lists ? [] :
  lists.map( d => { const {
                         dt_txt:예보일시,
                         weather:{description:날씨},
                         main:{temp:평균온도, temp_min:최저온도, temp_max:최고온도, humidity:습도},
                         wind:{speed:풍속},
                        } = d;
                   return {예보일시, 날씨, 평균온도, 최저온도, 최고온도, 습도, 풍속}; 
                }
          );

  return (
  <>
    <div>
      <button onClick={onClick}>불러오기</button> 
    </div>
    {data && <textarea rows={4} style={{textAlign:"left", width:"500px"}} value={JSON.stringify( r, null, 2)} />}
    <br />
    {data && <textarea rows={15} style={{textAlign:"left", width:"500px"}} value={JSON.stringify(r2, null, 2)} />}
    <br />
    {data && <textarea rows={45} style={{textAlign:"left", width:"500px"}} value={JSON.stringify(data, null, 2)} />}
  </>
  );
};

export default App;
