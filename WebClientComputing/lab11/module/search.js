const TOGGLE = 'search/TOGGLE';
const TYPE = 'search/CATEGORY';
const VALUE = 'search/VALUE';
const ARTICLE = 'search/ARTICLE';

export const toggleSearch = () => ({ type: TOGGLE});
export const categorySearch = (category) => ({ type:TYPE, payload:category });
export const valueSearch = (values) => ({ type: VALUE, payload:values });
export const articlesSearch = (articles) => ({ type: ARTICLE, payload:articles });

const initialState = {
    category : "all",
    country : "kr",
    topic : '',
    show : false,
    articles : null,
};
  
function search(state=initialState, action) {
  switch(action.type) {
    case TOGGLE: return { ...state, show : !state.show };
    case TYPE: return { ...state, category : action.payload };
    case VALUE: return { ...state, ...action.payload };
    case ARTICLE: return { ...state, articles : action.payload };
    default: return state;
  }
}

export default search;